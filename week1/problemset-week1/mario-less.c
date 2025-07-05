#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
void pyramidk(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Whats the height? ");
    }
    while (height < 1 || height > 8);
    pyramidk(height);
    pyramid(height);
}

void pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}


void pyramidk(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
