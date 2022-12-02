// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

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

// Hash table. Global variables are initialised to NULL at program start
node *table[N];

//dictionary size
int dsize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int bucket = hash(word);
    node *cursor = table[bucket];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
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
    //open dictionary file for reading. Store pointer in input
    FILE *input = fopen(dictionary, "r");
    // if file could not be opened the pointer will be NULL. print error message
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    //read from the dictionary one string at a time and copy into array of chars wscn
    //size of array is max length of word plus 1 for null chars
    char wscn[LENGTH + 1];
    while (fscanf(input, "%s", wscn) != EOF)
    {
        //create a new node for each word at the address allocated by malloc
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //copy word into word element in node using arrow operator
        //Use strcopy function to copy word
        strcpy(n->word, wscn);
        //hash word to find index
        int hval = hash(wscn);
        if (table[hval] == NULL)
        {   //if it is the first node in that location in the hash table then insert the new node directly
            table[hval] = n
        }
        else
        {
            //pointing new node to first node in linked list
            n->next = table[hval];
            //set head pointer to point to new node
            //this avoids orphaning the linked list
            table[hval] = n;
        }
        dsize++;
    }
        fclose(input);
        return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int n = 0; n < N; n++)
    {
    node *cursor = table[n];
    node *tmp = cursor;
    while (cursor != NULL)
    {
        cursor = cursor->next;
        free(tmp);
        tmp = cursor;
    }
    }
    return true;
}
