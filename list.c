#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(sizeof(int) * 3);
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //Time passes

    int *tmp = malloc(sizeof(int)* 4);
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    free(list);

    list = tmp;

    free(tmp);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    return 0;
}