#include "helpers.h"

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
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    //iterate over 2d array
    float count = 0.00;
    int redsum = 0;
    int greensum = 0;
    int bluesum = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                for (int m = -1; m <= 1; m++)
                {
                    if (i + k >= 0 && i + k < height && j + m >= 0 && j + m < width)
                    {
                        count++;
                        redsum += copy[i + k][j + m].rgbtRed;
                        bluesum += copy[i + k][j + m].rgbtBlue;
                        greensum += copy[i + k][j + m].rgbtGreen;
                    }
                }
            }
            image[i][j].rgbtBlue = round(bluesum / count);
            image[i][j].rgbtRed = round(redsum / count);
            image[i][j].rgbtGreen = round(greensum / count);

            count = 0;
            redsum = bluesum = greensum = 0;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
        //create a copy of the array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    //iterate over 2d array
    float count = 0.00;
    int redgx = 0;
    int greengx = 0;
    int bluegx = 0;
    int redgy = 0;
    int greengy = 0;
    int bluegy = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                for (int m = -1; m <= 1; m++)
                {
                    if (i + k >= 0 && i + k < height && j + m >= 0 && j + m < width)
                    {
                        count++;
                        redgx += copy[i + k][j + m].rgbtRed;
                        redgy += copy[i + k][j + m].rgbtRed;
                        bluegx += copy[i + k][j + m].rgbtBlue;
                        bluegy += copy[i + k][j + m].rgbtBlue;
                        greengx += copy[i + k][j + m].rgbtGreen;
                        greengy += copy[i + k][j + m].rgbtGreen;
                    }
                    else
                    {
                        
                    }
                }
            }
            image[i][j].rgbtBlue =
            image[i][j].rgbtRed =
            image[i][j].rgbtGreen =

            count = 0;
            redgx = redgy = bluegx = bluegy = greengx = greengy = 0;
        }
    }
    return;
}
