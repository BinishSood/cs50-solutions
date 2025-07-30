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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                                 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                                   0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                                  0.131 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed = minx(sepiaRed);
            image[i][j].rgbtGreen = minx(sepiaGreen);
            image[i][j].rgbtBlue = minx(sepiaBlue);
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
