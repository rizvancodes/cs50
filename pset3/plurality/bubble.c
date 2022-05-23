#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    int argv[] = {5, 4, 6, 2, 4, 1, 23, 3414, 342, 1313};
    int i, j, k, x;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (argv[j] > argv[j + 1])
            {
                x = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = x;
            }
        }
    }
    printf("Elements of given array: \n");
    for (k = 0; k < 10; k++)
    {
        printf("%d ", argv[k]);
    }
    printf("\n");
    return 0;
}