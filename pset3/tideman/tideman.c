#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int start, int end);
int find_winner(int column, int row);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    int i;
    for (i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int i, j;
    for (i = 0; i < candidate_count; i++)
    {
        for(j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    //check the first candidate in voter array
    //second element increment all remaining candidates by 1 apart from initial element
    //repeat until covered all candidate rows
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for(j = i + 1; j < MAX; j++)
        {
            if (preferences[i][j] != preferences[j][i])
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int i, j, k;
    pair x;
    for (i = 0; i < pair_count; i++)
    {
        for (j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] -  preferences[pairs[i].loser][pairs[i].winner] < preferences[pairs[j].winner][pairs[j].loser] -  preferences[pairs[j].loser][pairs[j].winner])
            {
                x = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = x;
            }
        }
    }
    return;
}
//This function is a recursive function to check whether a cycle is formed as a 2D array named locked pairs is being created
bool check_cycle(int start, int end)
{
    //Does the current loser equal the starting winner
    if (start == end)
    {
        return true;
    }
    // Loop through candidates (Recursive case)
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i] == true)
        {
            if (check_cycle(start, i) == true)
            {
                return true;
            }
        }
    }
    return false;

}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    int i;
    for (i = 0; i < pair_count; i++)
    {
        if (check_cycle(pairs[i].winner, pairs[i].loser) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

int find_winner(int column, int row)
{
    if (row == candidate_count)
    {
        return column;
    }

    else if (row != candidate_count)
    {
        if (locked[row][column] == true)
        {
        column++;
        row = 0;
        return find_winner(column, row);
        }

        if (locked[row][column] == false)
        {
        row++;
        return find_winner(column, row);
        }
    }
    return 1;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winner = find_winner(0, 0);
    printf("%s\n", candidates[winner]);
    return;
}