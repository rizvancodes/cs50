#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    int size = sizeof numbers / sizeof numbers[0];
    for(int i = 0; i < size; i++)
    {
        printf("%i\n", *(numbers + i));
    }
}