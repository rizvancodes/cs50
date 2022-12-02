#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool only_alpha(string arg);

string rotate(string p, string k);

bool duplicate_check(string arg);

int main(int argc, string argv[])
{   // verifying that command line args meet the conditions
    if ((argc > 2) || (argc < 2) || (!only_alpha(argv[1])) || (duplicate_check(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        string plaintext = get_string("plaintext: ");
        string ciphertext = rotate(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);
    }
}

//check that all characters are alpha
bool only_alpha(string arg)
{
    int l = strlen(arg), i;
    for (i = 0; i < l; i++)
    {   //isalpha returns 1 if alpha or 0 if non alpha
        if (isalpha(arg[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

string rotate(string p, string k)
{
//convert key to uppercase
//need to preserve the case of text
//therefore need a key for upper case and lower case
    int i;
    char upperkey[26];
    for (i = 0; i < strlen(k); i++)
    {
        char c = toupper(k[i]);
        upperkey[i] = c;
    }
//convert key to lowercase
    int l;
    char lowerkey[26];
    for (l = 0; l < strlen(k); l++)
    {
        char c = tolower(k[l]);
        lowerkey[l] = c;
    }

//substitute letters
    int m;
    for (m = 0; m < strlen(p); m++)
    {   
        if (isupper(p[m]) != 0)
        {   //
            int n = p[m] - 65;
            p[m] = upperkey[n];
        }
        if (islower(p[m]) != 0)
        {
            int n = p[m] - 97;
            p[m] = lowerkey[n];
        }
        else
        {
            p[m] = p[m];
        }
    }
    return p;
}

//check for duplicate letters in key
bool duplicate_check(string arg)
{
    int l = strlen(arg);
    for(int i = 0; i < l; i++)
    {
        for(int j = i + 1; j < l; j++)
        {
            if(arg[i] == arg[j])
            {
                return true;
            }
        }
    }
    return false;
}