#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    if (quarters > 1)
    {
        printf("%i quarters\n", quarters);
    }
    else if (quarters == 1)
    {
        printf("%i quarter\n", quarters);
    }
    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    if (dimes > 1)
    {
        printf("%i dimes\n", dimes);
    }
    else if (dimes == 1)
    {
        printf("%i dime\n", dimes);
    }

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    if (nickels > 1)
    {
        printf("%i nickels\n", nickels);
    }
    else if (nickels == 1)
    {
        printf("%i nickel\n", nickels);
    }

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    if (pennies > 1)
    {
        printf("%i pennies\n", pennies);
    }
    else if (pennies == 1)
    {
        printf("%i penny\n", pennies);
    }

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Total number of coins: %i\n", coins);
}

int get_cents(void)
{
    // TODO
    int n;
    do
    {
        n = get_int("Number of cents: ");
    }
    while (n < 0);
    return n;
}

int calculate_quarters(int cents)
{
    // TODO
    return cents / 25;
}

int calculate_dimes(int cents)
{
    // TODO
    return cents / 10;
}

int calculate_nickels(int cents)
{
    // TODO
    return cents / 5;
}

int calculate_pennies(int cents)
{
    // TODO
    return cents / 1;
}
