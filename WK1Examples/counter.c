#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int i = 1;
    while (i<=33)
    {
        printf("%i ", i);
        i+=i;
    }
    printf("\n");
}