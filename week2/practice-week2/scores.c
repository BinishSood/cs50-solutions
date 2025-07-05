#include <cs50.h>
#include <stdio.h>

const int N = 3;

float average(int x, int scores[]);

int main(void)
{
    int scores[N];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score : ");
    }
    printf("Average : %f\n", average(N, scores));
}

float average(int x, int scores[])
{
    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        sum += scores[i];
    }
    return sum / (float) x;
}
