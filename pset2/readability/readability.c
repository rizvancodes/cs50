#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    string sample = get_string("Text: ");
    int lettercount = count_letters(sample);
    printf("%i letters\n", lettercount);
    int wordcount = count_words(sample);
    printf("%i words\n", wordcount);
    int sentencecount = count_sentences(sample);
    printf("%i sentences\n", sentencecount);
    float L = ((float)lettercount / (float)wordcount) * 100;
    float S = ((float)sentencecount / (float)wordcount) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int i, sum = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int count_words(string text)
{
    int i, sum = 1;
    for (i = 0; i < strlen(text); i++)
    {
        if ((text[i]) == 32)
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int i, sum = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (((text[i]) == 46) || ((text[i]) == 63) || ((text[i]) == 33))
        {
            sum = sum + 1;
        }
    }
    return sum;
}
