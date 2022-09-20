#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int h = 0;
    do
    {
        //getting the height from user
        //the height shot be in the range
        //  1~8
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (int i = 0; i < h; i++)
    {
        /* code */
        for (int j = h - 1 - i; j > 0; j--)
        {
            // left spacing
            printf(" ");
        }
        for (int k = h - i - 1; k < h; k++)
        {
            // right #
            printf("#");
        }
        // middel spacing
        printf("  ");
        for (int k = h - i - 1; k < h; k++)
        {
            // left #
            printf("#");
        }

        printf("\n");
    }
}