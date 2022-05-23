#include <cs50.h>
#include <stdio.h>

int main(void)
{
//get user input
    int h;
    do
    {
        h = get_int("Height ");
    }
//if height is less than 1 or greater than 8 the. repeat
    while (h < 1 || h > 8);
//initialize parent loop. stop when iteration no. is less than height
    for (int i = 0; i < h; i++)
    {
//initalize child loop. Print spaces equal to the height minus the iteration number
        for (int k = 1; k < h - i; k++)
        {
            printf(" ");
        }
//initalize child loop. Print # equal to iteration number
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
//initalize child loop. Print 2 spaces after #'s
        printf("  ");
//initalize child loop. Print # equal to iteration number
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
//initalize child loop. Print new line and restart loop until iteration number is equal to height
        printf("\n");
    }
}
