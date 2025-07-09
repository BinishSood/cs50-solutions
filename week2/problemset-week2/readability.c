#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void grade_level(string text);

int main(void)
{
    string text = get_string("Text : ");
    grade_level(text);
}

void grade_level(string text)
{
    int L = 0;
    int S = 0;
    int W = 1;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            L++;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            S++;
        }
        if (text[i] == ' ')
        {
            W++;
        }
    }
    float y = 100.0 / W;
    int grade = round(0.0588 * L * y - 0.296 * S * y - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
