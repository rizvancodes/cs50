// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

//dictionary size
int dsize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashval = hash(word);
    node *cursor = table[hashval];
    while (cursor != NULL)
    {
        if (strcasecmp())
        cursor = cursor->next
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    //read from the dictionary one string at a time and copy into array of char, word
    char wscn[LENGTH + 1];
    while (fscanf(input, "%s", wscn) != EOF)
    {
        //create a new node for each word
        node *n = malloc(sizeof(node))
        if (n == NULL)
        {
            return false;
        }
        //copy word into node
        strcopy(n->word, wscn);
        //hash word to find index
        int hval = hash(word);
        //set next pointer as first node in linked list
        n->next = table[hval];
        //set head pointer to point to new node
        table[hval]->next = n;
        dsize++;
    }
        fclose(input);
        return true;
    }

    //hash word to obtain hash value
    //insert node into hash table at that location
    n->next = NULL;
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded == true)
    {
    return dsize;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
