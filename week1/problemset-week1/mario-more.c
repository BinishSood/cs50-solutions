#include <cs50.h>
#include <stdio.h>

void double_pyramid(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("What is the height? ");
    }
    while(height < 1 || height > 8);
    double_pyramid(height);
}

void double_pyramid(int height)
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
        printf("  ");
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
