#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float x = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            int avg = round(x);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
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
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            if ((round(sepiaRed) > 255))
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }
            if ((round(sepiaGreen) > 255))
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }
            if ((round(sepiaBlue) > 255))
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width / 2.0); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a copy of the array
    RGBTRIPLE copy[height][width]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width / 2.0); j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //iterate over 2d array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width / 2.0); j++)
        {
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round(copy[i][j].rgbtred + copy[i + 1][j].rgbtred + copy[i + 1][j + 1].rgbtred + copy[i][j +1 ].rgbtred / 4.0);
                image[i][j].rgbtGreen = round(copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen / 4.0);
                image[i][j].rgbtBlue = round(copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue / 4.0);
            }
            else if (i == 0 && j == (width - 1))
            {
                image[i][j].rgbtRed = round(copy[i][j].rgbtred + copy[i + 1][j].rgbtred + copy[i + 1][j - 1].rgbtred + copy[i][j - 1].rgbtred / 4.0);
                image[i][j].rgbtGreen = round(copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i][j - 1].rgbtGreen / 4.0);
                image[i][j].rgbtBlue = round(copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i][j - 1].rgbtBlue / 4.0);
            }
            else if (i == (height - 1) && j == 0)
            {
                image[i][j].rgbtRed = round(copy[i][j].rgbtred + copy[i - 1][j].rgbtred + copy[i - 1][j + 1].rgbtred + copy[i][j + 1].rgbtred / 4.0);
                image[i][j].rgbtGreen = round(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen / 4.0);
                image[i][j].rgbtBlue = round(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue / 4.0);
            }
            else if (i == (height - 1) && j == (width - 1))
            {
                image[i][j].rgbtRed = round(copy[i][j].rgbtred + copy[i - 1][j].rgbtred + copy[i - 1][j - 1].rgbtred + copy[i][j - 1].rgbtred / 4.0);
                image[i][j].rgbtGreen = round(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j - 1].rgbtGreen / 4.0);
                image[i][j].rgbtBlue = round(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j - 1].rgbtBlue / 4.0);
            }
            else if (i > 0 && j == (width - 1))
            {
                image[i][j].rgbtRed = round(copy[i][j].rgbtred + copy[i - 1][j].rgbtred + copy[i - 1][j - 1].rgbtred + copy[i][j - 1].rgbtred / 4.0);
                image[i][j].rgbtGreen = round(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j - 1].rgbtGreen / 4.0);
                image[i][j].rgbtBlue = round(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j - 1].rgbtBlue / 4.0);
            }
        }
    }
    return;
}
