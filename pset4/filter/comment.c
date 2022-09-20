
    //RGBTRIPLE copy [height + 2][width + 2];

/*
    for (int i = 0; i < height+2; i++)
    {
        for (int j = 0; j < width+2; j++)
        {
            if (i==0 || i == height+1 || j == 0 || j == width+1)
            {
                copy [i][j].rgbtBlue  = 0;
                copy [i][j].rgbtRed   = 0;
                copy [i][j].rgbtGreen = 0;
            }
            else
            {
                copy [i][j].rgbtBlue  = image [i - 1][j - 1].rgbtBlue;
                copy [i][j].rgbtRed   = image [i - 1][j - 1].rgbtRed;
                copy [i][j].rgbtGreen = image [i - 1][j - 1].rgbtGreen;

            }
        }

    }*/

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