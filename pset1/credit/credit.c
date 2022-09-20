#include <stdio.h>
#include <cs50.h>
#include <math.h>
int sum(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x = (x - (x % 10)) / 10;
    }
    return sum;
}

int main(void)
{
    //variables
    int d = 0;
    long card1 = get_long("Number: ");
    long card2 = card1;
    int sum1 = 0, sum2 = 0;

    int t0 = (card1 - (card1 % 100000000000000)) / 100000000000000;
    if((card1 - (card1 % 1000000000000000)) / 1000000000000000 == 0)
    {
        t0 = (card1 - (card1 % 10000000000000)) / 10000000000000;
    }
    for (int i = 0; i < 8; i++)
    {
        d = card1 % 10;
        //sum of the digits that weren’t multiplied by 2
        sum2 += d;
        card1 = (card1 - d) / 10;
        d = card1 % 10;
        // sum of the  products’ digits
        sum1 += sum(d * 2);
        card1 = (card1 - d) / 10;
    }
    // add sum of product's digits to the sum of the digits that weren’t multiplied by 2
    int v0 = sum2 + sum1;
    if (v0 % 10 != 0 || card2 % 1000000000000 == 0)
    {
        //*** problem ***//
        // s 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit
        printf("INVALID\n");
    }
    else if (v0 % 10 == 0)
    {
        if (t0 == 51 || t0 == 52 || t0 == 53 || t0 == 54 || t0 == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (t0 == 34 || t0 == 37)
        {
            printf("AMEX\n");
        }
        else if ((t0 - (t0 % 10)) / 10 == 4)
        {
            printf("VISA\n");
        }
    }
}