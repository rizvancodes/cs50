#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = "HI";
    char c = s[0];
    char *p = &s;
    printf("%p\n", c);
    printf("%p\n", p);

}