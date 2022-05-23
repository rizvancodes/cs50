#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool only_digits(string arg);

string rotate(string p, int k);

int main(int argc, string argv[])
{
    if ((argc > 2) || (argc < 2) || (!only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        string ciphertext = rotate(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);
    }
}

bool only_digits(string arg)
{
    int l = strlen(arg), i;
    for (i = 0; i < l; i++)
    {
        if (isdigit(arg[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

string rotate(string p, int k)
{
    int l = strlen(p), i;
    for (i = 0; i < l; i++)
    {
        if (isalpha(p[i]))
        {
            if(islower(p[i]) != 0)
            {
                p[i] = ((((p[i]) - 97) + k) % 26) + 97;
            }
            if(isupper(p[i]) != 0)
            {
                p[i] = ((((p[i]) - 65) + k) % 26) + 65;
            }
        }
        else
        {
            p[i] = p[i];
        }
    }
    return p;
}

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
    return false;
}