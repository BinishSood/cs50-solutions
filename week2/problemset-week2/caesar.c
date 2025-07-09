#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    int len = strlen(argv[1]);
    string k = argv[1];
    int key = atoi(argv[1]);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(k[i]))
        {
            printf("Usage : ./caesar key\n");
            return 1;
        }
        if (key < 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    string p = get_string("Plaintext :  ");
    int lenp = strlen(p);
    for (int j = 0; j < lenp; j++)
    {
        if (isupper(p[j]))
        {
            p[j] = ((p[j] - 'A' + key) % 26) + 'A';
        }
        else if (islower(p[j]))
        {
            p[j] = ((p[j] - 'a' + key) % 26) + 'a';
        }
    }
    printf("ciphertext: %s\n", p);
    return 0;
}
