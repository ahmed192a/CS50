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


int cap (int val)
{
    return val < 255 ? val : 255;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE Gx [height][width];
    RGBTRIPLE Gy [height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2},{-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0},{1, 2, 1}};
    int avgred_x = 0, avggreen_x = 0, avgblue_x = 0;
    int avgred_y = 0, avggreen_y = 0, avgblue_y = 0;

    RGBTRIPLE copy [height + 2][width + 2];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy [i + 1][j + 1] = image [i][j];
        }
    }

    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            avgred_x   = 0;
            avggreen_x = 0;
            avgblue_x  = 0;
            avgred_y   = 0;
            avggreen_y = 0;
            avgblue_y  = 0;

            for (int ii = 0; ii < 3; ii++)
            {
                for (int jj = 0; jj < 3; jj++)
                {
                    avgblue_x  += gx [ii][jj] * copy[i-1+ii][j-1+jj].rgbtBlue;
                    avgred_x   += gx [ii][jj] * copy[i-1+ii][j-1+jj].rgbtRed;
                    avggreen_x += gx [ii][jj] * copy[i-1+ii][j-1+jj].rgbtGreen;

                    avgblue_y  += gy [ii][jj] * copy[i-1+ii][j-1+jj].rgbtBlue;
                    avgred_y   += gy [ii][jj] * copy[i-1+ii][j-1+jj].rgbtRed;
                    avggreen_y += gy [ii][jj] * copy[i-1+ii][j-1+jj].rgbtGreen;
                }
            }
            Gx [i-1][j-1].rgbtBlue  = avgblue_x;
            Gx [i-1][j-1].rgbtRed   = avgred_x;
            Gx [i-1][j-1].rgbtGreen = avggreen_x;

            Gy [i-1][j-1].rgbtBlue  = avgblue_y;
            Gy [i-1][j-1].rgbtRed   = avgred_y;
            Gy [i-1][j-1].rgbtGreen = avggreen_y;
        }
    }





    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue  = cap(round(sqrt(pow(Gx [i][j].rgbtBlue ,2) +pow(Gy [i][j].rgbtBlue ,2))));
            image[i][j].rgbtRed   = cap(round(sqrt(pow(Gx [i][j].rgbtRed  ,2) +pow(Gy [i][j].rgbtRed  ,2))));
            image[i][j].rgbtGreen = cap(round(sqrt(pow(Gx [i][j].rgbtGreen,2) +pow(Gy [i][j].rgbtGreen,2))));
        }
    }
}

/*

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgred_x   = 0;
            avggreen_x = 0;
            avgblue_x  = 0;
            avgred_y   = 0;
            avggreen_y = 0;
            avgblue_y  = 0;

            if (i == 0)
            {
                if (j == 0)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgblue_x  += gx [1+ii][1+jj] * image[ii][jj].rgbtBlue;
                            avgred_x   += gx [1+ii][1+jj] * image[ii][jj].rgbtRed;
                            avggreen_x += gx [1+ii][1+jj] * image[ii][jj].rgbtGreen;

                            avgblue_y  += gy [1+ii][1+jj] * image[ii][jj].rgbtBlue;
                            avgred_y   += gy [1+ii][1+jj] * image[ii][jj].rgbtRed;
                            avggreen_y += gy [1+ii][1+jj] * image[ii][jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
                //---------------------------------------------------------
                else if (j == width - 1)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgblue_x  += gx [1+ii][1-jj] * image[i+ii][j-jj].rgbtBlue;
                            avgred_x   += gx [1+ii][1-jj] * image[i+ii][j-jj].rgbtRed;
                            avggreen_x += gx [1+ii][1-jj] * image[i+ii][j-jj].rgbtGreen;

                            avgblue_y  += gy [1+ii][1-jj] * image[i+ii][j-jj].rgbtBlue;
                            avgred_y   += gy [1+ii][1-jj] * image[i+ii][j-jj].rgbtRed;
                            avggreen_y += gy [1+ii][1-jj] * image[i+ii][j-jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
                //---------------------------------------------------------
                else
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 3; jj++)
                        {
                            avgblue_x  += gx [1+ii][jj] * image[i+ii][j-1+jj].rgbtBlue;
                            avgred_x   += gx [1+ii][jj] * image[i+ii][j-1+jj].rgbtRed;
                            avggreen_x += gx [1+ii][jj] * image[i+ii][j-1+jj].rgbtGreen;

                            avgblue_y  += gy [1+ii][jj] * image[i+ii][j-1+jj].rgbtBlue;
                            avgred_y   += gy [1+ii][jj] * image[i+ii][j-1+jj].rgbtRed;
                            avggreen_y += gy [1+ii][jj] * image[i+ii][j-1+jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
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
                            avgblue_x  += gx [1-ii][1+jj] * image[i-ii][j+jj].rgbtBlue;
                            avgred_x   += gx [1-ii][1+jj] * image[i-ii][j+jj].rgbtRed;
                            avggreen_x += gx [1-ii][1+jj] * image[i-ii][j+jj].rgbtGreen;

                            avgblue_y  += gy [1-ii][1+jj] * image[i-ii][j+jj].rgbtBlue;
                            avgred_y   += gy [1-ii][1+jj] * image[i-ii][j+jj].rgbtRed;
                            avggreen_y += gy [1-ii][1+jj] * image[i-ii][j+jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
                //---------------------------------------------------------
                else if (j == width - 1)
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgblue_x  += gx [1-ii][1-jj] * image[i-ii][j-jj].rgbtBlue;
                            avgred_x   += gx [1-ii][1-jj] * image[i-ii][j-jj].rgbtRed;
                            avggreen_x += gx [1-ii][1-jj] * image[i-ii][j-jj].rgbtGreen;

                            avgblue_y  += gy [1-ii][1-jj] * image[i-ii][j-jj].rgbtBlue;
                            avgred_y   += gy [1-ii][1-jj] * image[i-ii][j-jj].rgbtRed;
                            avggreen_y += gy [1-ii][1-jj] * image[i-ii][j-jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
                //---------------------------------------------------------
                else
                {
                    for (int ii = 0; ii < 2; ii++)
                    {
                        for (int jj = 0; jj < 3; jj++)
                        {
                            avgblue_x  += gx [1-ii][jj] * image[i-ii][j-1+jj].rgbtBlue;
                            avgred_x   += gx [1-ii][jj] * image[i-ii][j-1+jj].rgbtRed;
                            avggreen_x += gx [1-ii][jj] * image[i-ii][j-1+jj].rgbtGreen;

                            avgblue_y  += gy [1-ii][jj] * image[i-ii][j-1+jj].rgbtBlue;
                            avgred_y   += gy [1-ii][jj] * image[i-ii][j-1+jj].rgbtRed;
                            avggreen_y += gy [1-ii][jj] * image[i-ii][j-1+jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
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
                            avgblue_x  += gx [ii][jj+1] * image[i-1+ii][j+jj].rgbtBlue;
                            avgred_x   += gx [ii][jj+1] * image[i-1+ii][j+jj].rgbtRed;
                            avggreen_x += gx [ii][jj+1] * image[i-1+ii][j+jj].rgbtGreen;

                            avgblue_y  += gy [ii][jj+1] * image[i-1+ii][j+jj].rgbtBlue;
                            avgred_y   += gy [ii][jj+1] * image[i-1+ii][j+jj].rgbtRed;
                            avggreen_y += gy [ii][jj+1] * image[i-1+ii][j+jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
                //---------------------------------------------------------
                else if (j == width - 1)
                {
                    for (int ii = 0; ii < 3; ii++)
                    {
                        for (int jj = 0; jj < 2; jj++)
                        {
                            avgblue_x  += gx [ii][1-jj] * image[i-1+ii][j-jj].rgbtBlue;
                            avgred_x   += gx [ii][1-jj] * image[i-1+ii][j-jj].rgbtRed;
                            avggreen_x += gx [ii][1-jj] * image[i-1+ii][j-jj].rgbtGreen;

                            avgblue_y  += gy [ii][1-jj] * image[i-1+ii][j-jj].rgbtBlue;
                            avgred_y   += gy [ii][1-jj] * image[i-1+ii][j-jj].rgbtRed;
                            avggreen_y += gy [ii][1-jj] * image[i-1+ii][j-jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
                else if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
                {
                    for (int ii = 0; ii < 3; ii++)
                    {
                        for (int jj = 0; jj < 3; jj++)
                        {
                            avgblue_x  += gx [ii][jj] * image[i-1+ii][j-1+jj].rgbtBlue;
                            avgred_x   += gx [ii][jj] * image[i-1+ii][j-1+jj].rgbtRed;
                            avggreen_x += gx [ii][jj] * image[i-1+ii][j-1+jj].rgbtGreen;

                            avgblue_y  += gy [ii][jj] * image[i-1+ii][j-1+jj].rgbtBlue;
                            avgred_y   += gy [ii][jj] * image[i-1+ii][j-1+jj].rgbtRed;
                            avggreen_y += gy [ii][jj] * image[i-1+ii][j-1+jj].rgbtGreen;
                        }
                    }
                    Gx [i][j].rgbtBlue  = avgblue_x;
                    Gx [i][j].rgbtRed   = avgred_x;
                    Gx [i][j].rgbtGreen = avggreen_x;

                    Gy [i][j].rgbtBlue  = avgblue_y;
                    Gy [i][j].rgbtRed   = avgred_y;
                    Gy [i][j].rgbtGreen = avggreen_y;
                }
            }

        }
    }

*/