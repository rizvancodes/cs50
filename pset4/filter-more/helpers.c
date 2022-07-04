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
            //iterate row in 3x3 box
            for (int k = -1; k <= 1; k++)
            {
                //iterate column in 3x3 box
                for (int m = -1; m <= 1; m++)
                {
                    //[i][j] is the current array item; k is the step required to select the previous row; m is the step required to select the previous column
                    //in the first iteration [i - 1][j - 1] will be the first item in the 3x3 box surrounding [i][j];
                    //we will iterate through the array going from left to right until we reach the third column at which point m = 1
                    //we then continue to iterate through the rows until k = 1
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
    int redgx = 0;
    int greengx = 0;
    int bluegx = 0;
    int redgy = 0;
    int greengy = 0;
    int bluegy = 0;

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

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
                            redgx += gx[k + 1][m + 1] * copy[i + k][j + m].rgbtRed;
                            redgy += gy[k + 1][m + 1] * copy[i + k][j + m].rgbtRed;
                            bluegx += gx[k + 1][m + 1] * copy[i + k][j + m].rgbtBlue;
                            bluegy += gy[k + 1][m + 1] * copy[i + k][j + m].rgbtBlue;
                            greengx += gx[k + 1][m + 1] * copy[i + k][j + m].rgbtGreen;
                            greengy += gy[k + 1][m + 1] * copy[i + k][j + m].rgbtGreen;
                            }
                            else
                            {
                            redgx += 0;
                            redgy += 0;
                            bluegx += 0;
                            bluegy += 0;
                            greengx += 0;
                            greengy += 0;
                            }
                    }
            }
            if (round(sqrt((redgx*redgx)+(redgy*redgy))) <= 255)
            {
                image[i][j].rgbtBlue = round(sqrt((redgx*redgx)+(redgy*redgy)));
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            if (round(sqrt((bluegx*bluegx)+(bluegy*bluegy))) > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sqrt((bluegx*bluegx)+(bluegy*bluegy)));
            }
            if (round(sqrt((greengx*greengx)+(greengy*greengy))) > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sqrt((greengx*greengx)+(greengy*greengy)));
            }

            redgx = redgy = bluegx = bluegy = greengx = greengy = 0;
        }
    }
    return;
}
