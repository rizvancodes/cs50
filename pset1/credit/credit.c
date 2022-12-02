#include <cs50.h>
#include <stdio.h>

long get_card(void);

long get_alt(long num);

long get_product(long alt);

int get_altpsum(long altp);

long get_rem(long num);

int get_remsum(long rem);

int sum(int remsum, int altpsum);

long rev_num(long num);

int cardtype(long revnum);

int num_length(long num);

int main(void)
{
//Get card number from user
    long cardnum = get_card();
//get alternate digits starting from second to last digit and reverse
    long altdig = get_alt(cardnum);
//product of alternate digits
    long product = get_product(altdig);
//sum of product of alternate digits
    int productsum = get_altpsum(product);
//get remaining digits starting from last digit and reverse
    long remaining = get_rem(cardnum);
//sum remaining digits
    int sumremaining = get_remsum(remaining);
// reverse card number
    long reversenum = rev_num(cardnum);
    int checksum = sum(sumremaining, productsum);
// check card type and checksum
    int cardlength = num_length(cardnum);
// check first two digits
    int firsttwo = cardtype(reversenum);
    if ( (firsttwo == 34 || firsttwo == 37) && (cardlength == 15) && (checksum % 10 == 0) )
    {
        printf("AMEX\n");
    }
    else if ( (firsttwo == 51 || firsttwo == 52 || firsttwo == 53 || firsttwo == 54 || firsttwo == 55) && (cardlength == 16) && (checksum % 10 == 0) )
    {
        printf("MASTERCARD\n");
    }
    else if ( (reversenum % 10 == 4) && (cardlength == 13 || cardlength == 16) && (checksum % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_card(void)
{   
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);
    return num;
}

long get_alt(long num)
{
    long alt = 0;
    while (num > 0)
    {   //
        num = num / 10;
        alt = alt * 10 + num % 10;
        num = num / 10;
    }
    return alt;
}

long get_product(long alt)
{
    long altp = 0;
    int prod;
    while (alt > 0)
    {
        prod = 2 * (alt % 10);
        altp = altp * 100 + prod;
        alt = alt / 10;
    }
    return altp;
}

int get_altpsum(long altp)
{
    int altpsum = 0;
    while (altp > 0)
    {
        altpsum = altpsum + (altp % 10);
        altp = altp / 10;
    }
    return altpsum;
}

long get_rem(long num)
{
    long rem = 0;
    while (num > 0)
    {
        rem = rem * 10 + num % 10;
        num = num / 100;
    }
    return rem;
}

int get_remsum(long rem)
{
    int remsum = 0;
    while (rem > 0)
    {
        remsum = remsum + (rem % 10);
        rem = rem / 10;
    }
    return remsum;
}

int sum(int remsum, int altpsum)
{
    int finalsum;
    return finalsum = remsum + altpsum;
}

long rev_num(long num)
{
    long revnum = 0;
    do
    {
        revnum = revnum * 10 + num % 10;
        num = num / 10;
    }
    while (num > 0);
    return revnum;
}

int cardtype(long revnum)
{
    int checkdig = 0;
    do
    {
        checkdig = checkdig * 10 + revnum % 10;
        revnum = revnum / 10;
    }
    while (checkdig < 10);
    return checkdig;
}

int num_length(long num)
{
    int i = 0;
    while (num > 0)
    {
        num = num / 10;
        i++;
    }
    return i;
}