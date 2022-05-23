#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    int argv[] = {5, 4, 6, 2, 4, 1, 23, 3414, 342, 1313};
    int i, j, k, x;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (argv[i] < argv[j])
            {
                x = argv[i];
                argv[i] = argv[j];
                argv[j] = x;
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
