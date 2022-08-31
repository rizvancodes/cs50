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
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
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
    char wscn[malloc(sizeof(LENGTH + 1))]
    while (fscanf(input, "%s", wscn) != EOF)
    {
        //create a new node for each word
        node *n = malloc(sizeof(node))
        if (n == NULL)
        {
            return false;
        }
        //copy word into node
        strcopy(n->word, wscn)
        //set next pointer as NULL
        n->next = NULL;
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
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
