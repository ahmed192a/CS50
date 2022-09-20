#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < floor(width / 2); j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy [height][width];
    int avgred = 0, avggreen = 0, avgblue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgred = 0;
            avggreen = 0;
            avgblue = 0;

            if (i == 0)
            {
                if (j == 0)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgred   += image[i + ii][j + jj].rgbtRed;
                            avggreen += image[i + ii][j + jj].rgbtGreen;
                            avgblue  += image[i + ii][j + jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 4.0);
                    copy[i][j].rgbtGreen = round(avggreen / 4.0);
                    copy[i][j].rgbtRed   = round(avgred / 4.0);
                }
                //---------------------------------------------------------
                else if (j == width - 1)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgred   += image[i + ii][j - jj].rgbtRed;
                            avggreen += image[i + ii][j - jj].rgbtGreen;
                            avgblue  += image[i + ii][j - jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 4.0);
                    copy[i][j].rgbtGreen = round(avggreen / 4.0);
                    copy[i][j].rgbtRed   = round(avgred / 4.0);
                }
                //---------------------------------------------------------
                else
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 3; jj++)
                        {
                            avgred   += image[i + ii][j - 1 + jj].rgbtRed;
                            avggreen += image[i + ii][j - 1 + jj].rgbtGreen;
                            avgblue  += image[i + ii][j - 1 + jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 6.0);
                    copy[i][j].rgbtGreen = round(avggreen / 6.0);
                    copy[i][j].rgbtRed   = round(avgred / 6.0);
                }
            }
            //---------------------------------------------------------
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgred   += image[i - ii][j + jj].rgbtRed;
                            avggreen += image[i - ii][j + jj].rgbtGreen;
                            avgblue  += image[i - ii][j + jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 4.0);
                    copy[i][j].rgbtGreen = round(avggreen / 4.0);
                    copy[i][j].rgbtRed   = round(avgred / 4.0);
                }
                //---------------------------------------------------------
                else if (j == width - 1)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgred   += image[i - ii][j - jj].rgbtRed;
                            avggreen += image[i - ii][j - jj].rgbtGreen;
                            avgblue  += image[i - ii][j - jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 4.0);
                    copy[i][j].rgbtGreen = round(avggreen / 4.0);
                    copy[i][j].rgbtRed   = round(avgred / 4.0);
                }
                //---------------------------------------------------------
                else
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 3; jj++)
                        {
                            avgred   += image[i - ii][j - 1 + jj].rgbtRed;
                            avggreen += image[i - ii][j - 1 + jj].rgbtGreen;
                            avgblue  += image[i - ii][j - 1 + jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 6.0);
                    copy[i][j].rgbtGreen = round(avggreen / 6.0);
                    copy[i][j].rgbtRed   = round(avgred / 6.0);
                }
            }
            //---------------------------------------------------------
            else if (i < height - 1 && i > 0)
            {
                if (j == 0)
                {
                    for (int ii = 0; ii < 3; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgred   += image[i - 1 + ii][j + jj].rgbtRed;
                            avggreen += image[i - 1 + ii][j + jj].rgbtGreen;
                            avgblue  += image[i - 1 + ii][j + jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 6.0);
                    copy[i][j].rgbtGreen = round(avggreen / 6.0);
                    copy[i][j].rgbtRed   = round(avgred / 6.0);
                }
                //---------------------------------------------------------
                else if (j == width - 1)
                {
                    for (int ii = 0; ii < 3; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgred   += image[i - 1 + ii][j - jj].rgbtRed;
                            avggreen += image[i - 1 + ii][j - jj].rgbtGreen;
                            avgblue  += image[i - 1 + ii][j - jj].rgbtBlue;
                        }
                    }
                    copy[i][j].rgbtBlue  = round(avgblue / 6.0);
                    copy[i][j].rgbtGreen = round(avggreen / 6.0);
                    copy[i][j].rgbtRed   = round(avgred / 6.0);
                }
                else
                {
                    if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
                    {
                        for (int ii = 0; ii < 3; ii++)
                        {
                            for (int jj = 0; jj < 3; jj++)
                            {
                                avgred   += image[i - 1 + ii][j - 1 + jj].rgbtRed;
                                avggreen += image[i - 1 + ii][j - 1 + jj].rgbtGreen;
                                avgblue  += image[i - 1 + ii][j - 1 + jj].rgbtBlue;
                            }
                        }
                        copy[i][j].rgbtBlue  = round(avgblue / 9.0);
                        copy[i][j].rgbtGreen = round(avggreen / 9.0);
                        copy[i][j].rgbtRed   = round(avgred / 9.0);
                    }
                }
            }
            //---------------------------------------------------------
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}

