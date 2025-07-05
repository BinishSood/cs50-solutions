#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool check_validity(long number);
void check_type(bool valid, long number);

int main(void)
{
    long number = get_long("Number ");
    check_type(check_validity(number), number);
}

bool check_validity(long number)
{
    int sumx = 0;
    int sumy = 0;
    while (number > 0)
    {
        int digitx = number % 10;
        sumx += digitx;
        number = number / 10;
        if (number > 0)
        {
            int digity = number % 10;
            int digityk = digity * 2;
            if (digityk > 9)
            {
                int digitykx = digityk / 10;
                int digityky = digityk % 10;
                sumy += digitykx + digityky;
                number = number / 10;
            }
            else
            {
                sumy += digityk;
                number = number / 10;
            }
        }
    }
    int sum3 = sumx + sumy;
    if (sum3 % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void check_type(bool valid, long number)
{
    int length = 0;
    long numberk = number;
    while (numberk > 0)
    {
        numberk = numberk / 10;
        length++;
    }
    long numberx = number;
    for (int i = 0; i < length - 2; i++)
    {
        numberx = numberx / 10;
    }
    int first_two = numberx;
    long numbery = number;
    for (int j = 0; j < length - 1; j++)
    {
        numbery = numbery / 10;
    }
    int first = numbery;
    if (valid == true)
    {
        if (length == 15)
        {
            if (first_two == 34 || first_two == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 16)
        {
            if (first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 ||
                first_two == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 13)
        {
            if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (valid == false)
    {
        printf("INVALID\n");
    }
}
