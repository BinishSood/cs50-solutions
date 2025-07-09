#include <cs50.h>
#include <stdio.h>
#include <string.h>

int points(string input);

int main(void)
{
    string input1 = get_string("Player 1 : ");
    string input2 = get_string("Player 2 : ");
    if (points(input1) > points(input2))
    {
        printf("Player 1 wins!\n");
    }
    else if (points(input1) < points(input2))
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int points(string input)
{
    int alphabets[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int len = strlen(input);
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] >= 65 && input[i] <= 90)
        {
            total += alphabets[input[i] - 65];
        }
        else if (input[i] >= 97 && input[i] <= 122)
        {
            total += alphabets[input[i] - 97];
        }
        else
        {
            total += 0;
        }
    }
    return total;
}
