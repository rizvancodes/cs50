#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int collatz(int);

int main(void)
{
    int x = get_int("Type your number: ");
    int collatz_number = collatz(x);
    printf("%i \n", collatz_number);
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz(3 * n + 1);
}