#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./substitution key\n");
        return 1;
    }
    int len = strlen(argv[1]);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string k = argv[1];
    for (int i = 0; i < len; i++)
    {
        if (isdigit(k[i]))
        {
            printf("Usage : ./substitution key\n");
            return 1;
        }
        for (int j = i + 1; j < len; j++)
        {
            if (i != j && toupper(k[i]) == toupper(k[j]))
            {
                printf("Key must contain 26 different characters.\n");
                return 1;
            }
        }
        if (!isalnum(k[i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    string p = get_string("Plaintext :  ");
    int lenp = strlen(p);
    char useu[26];
    char usel[26];
    for (int z = 0; z < 26; z++)
    {
        useu[z] = toupper(k[z]);
        usel[z] = tolower(k[z]);
    }
    for (int l = 0; l < lenp; l++)
    {
        if (isupper(p[l]))
        {
            p[l] = useu[p[l] - 'A'];
        }
        else if (islower(p[l]))
        {
            p[l] = usel[p[l] - 'a'];
        }
    }
    printf("ciphertext: %s\n", p);
    return 0;
}
