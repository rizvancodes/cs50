#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = "HI";
    printf("%p\n", s);
    printf("%c\n", *s);

    for(int i = 0; i < 3; i++)
    {
        printf("%c", *s + i);
    }
    printf("\n");
}