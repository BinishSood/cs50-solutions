#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./recover input");
        return 1;
    }
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("input file cannot be opened");
        return 1;
    }
    FILE *inputk = fopen(argv[1], "rb");
    int count = 0;
    uint8_t b[512];
    uint8_t bk[512];
    fread(&bk, 1, 512, inputk);
    while (!(bk[0] == 0xFF && bk[1] == 0xD8 && bk[2] == 0xFF && bk[3] >= 0xE0 && bk[3] <= 0xEF))
    {
        fread(&b, 1, 512, input);
        fread(&bk, 1, 512, inputk);
    }
    while (fread(&b, 1, 512, input) == 512)
    {
        char filename[8];
        if (b[0] == 0xFF && b[1] == 0xD8 && b[2] == 0xFF && b[3] >= 0xE0 && b[3] <= 0xEF)
        {
            sprintf(filename, "%03i.jpg", count);
            FILE *output = fopen(filename, "wb");
            fwrite(&b, 512, 1, output);
            fclose(output);
            count++;
        }
        else
        {
            FILE *output = fopen(filename, "ab");
            fwrite(&b, 1, 512, output);
            fclose(output);
        }
    }
    fclose(input);
    fclose(inputk);
}
