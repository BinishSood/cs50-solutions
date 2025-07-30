#include "helpers.h"
#include <math.h>

int minx(int x);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            if (x < 255)
            {
                image[i][j].rgbtRed = x;
                image[i][j].rgbtGreen = x;
                image[i][j].rgbtBlue = x;
            }
            else
            {
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 255;
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp[i][j];
            }
        }
        else
        {
            for (int j = 0; j < (width / 2) - 0.5; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            copy[k][l] = image[k][l];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 1;
            int redsum = copy[i][j].rgbtRed;
            int greensum = copy[i][j].rgbtGreen;
            int bluesum = copy[i][j].rgbtBlue;
            if (j - 1 > -1)
            {
                redsum += copy[i][j - 1].rgbtRed;
                greensum += copy[i][j - 1].rgbtGreen;
                bluesum += copy[i][j - 1].rgbtBlue;
                count++;
            }
            if (j + 1 < width)
            {
                redsum += copy[i][j + 1].rgbtRed;
                greensum += copy[i][j + 1].rgbtGreen;
                bluesum += copy[i][j + 1].rgbtBlue;
                count++;
            }
            if (i - 1 > -1)
            {
                redsum += copy[i - 1][j].rgbtRed;
                greensum += copy[i - 1][j].rgbtGreen;
                bluesum += copy[i - 1][j].rgbtBlue;
                count++;
            }
            if (i + 1 < height)
            {
                redsum += copy[i + 1][j].rgbtRed;
                greensum += copy[i + 1][j].rgbtGreen;
                bluesum += copy[i + 1][j].rgbtBlue;
                count++;
            }
            if (i - 1 > -1 && j - 1 > -1)
            {
                redsum += copy[i - 1][j - 1].rgbtRed;
                greensum += copy[i - 1][j - 1].rgbtGreen;
                bluesum += copy[i - 1][j - 1].rgbtBlue;
                count++;
            }
            if (i - 1 > -1 && j + 1 < width)
            {
                redsum += copy[i - 1][j + 1].rgbtRed;
                greensum += copy[i - 1][j + 1].rgbtGreen;
                bluesum += copy[i - 1][j + 1].rgbtBlue;
                count++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                redsum += copy[i + 1][j + 1].rgbtRed;
                greensum += copy[i + 1][j + 1].rgbtGreen;
                bluesum += copy[i + 1][j + 1].rgbtBlue;
                count++;
            }
            if (i + 1 < height && j - 1 > -1)
            {
                redsum += copy[i + 1][j - 1].rgbtRed;
                greensum += copy[i + 1][j - 1].rgbtGreen;
                bluesum += copy[i + 1][j - 1].rgbtBlue;
                count++;
            }
            image[i][j].rgbtRed = minx(round((float) redsum / count));
            image[i][j].rgbtGreen = minx(round((float) greensum / count));
            image[i][j].rgbtBlue = minx(round((float) bluesum / count));
        }
    }
    return;
}

int minx(int x)
{
    if (x < 255)
    {
        return x;
    }
    else
    {
        return 255;
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            copy[k][l] = image[k][l];
        }
    }
    int arrx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int arry[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxr = 0;
            int gyr = 0;
            int gxg = 0;
            int gyg = 0;
            int gxb = 0;
            int gyb = 0;
            int m = 0;
            for (int di = -1; di < 2; di++)
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    if (i + di < 0 || i + di >= height || j + dj < 0 || j + dj >= width)
                    {
                    }
                    else
                    {
                        gxr += copy[i + di][j + dj].rgbtRed * arrx[m];
                        gxg += copy[i + di][j + dj].rgbtGreen * arrx[m];
                        gxb += copy[i + di][j + dj].rgbtBlue * arrx[m];
                        gyr += copy[i + di][j + dj].rgbtRed * arry[m];
                        gyg += copy[i + di][j + dj].rgbtGreen * arry[m];
                        gyb += copy[i + di][j + dj].rgbtBlue * arry[m];
                    }
                    m++;
                }
            }
            int gr = minx(round(sqrt(gxr * gxr + gyr * gyr)));
            int gg = minx(round(sqrt(gxg * gxg + gyg * gyg)));
            int gb = minx(round(sqrt(gxb * gxb + gyb * gyb)));
            image[i][j].rgbtRed = gr;
            image[i][j].rgbtGreen = gg;
            image[i][j].rgbtBlue = gb;
        }
    }
    return;
}
