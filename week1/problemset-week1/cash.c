#include <cs50.h>
#include <stdio.h>

void min_coins(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Whats your input? ");
    }
    while (cents < 0);
    min_coins(cents);
}

void min_coins(int cents)
{
    int count = 0;
    if (cents >= 25)
    {
        do
        {
            cents = cents - 25;
            count++;
        }
        while (cents >= 25);
    }
    if (cents >= 10)
    {
        do
        {
            cents = cents - 10;
            count++;
        }
        while (cents >= 10);
    }
    if (cents >= 5)
    {
        do
        {
            cents = cents - 5;
            count++;
        }
        while (cents >= 5);
    }
    if (cents >= 1)
    {
        do
        {
            cents = cents - 1;
            count++;
        }
        while (cents >= 1);
    }
    printf("%i\n", count);
}
