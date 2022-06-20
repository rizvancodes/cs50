#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = "HI!";
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}