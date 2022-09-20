#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // ckeck the inputs
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);
    // change dollars into cents
    int cents = round(dollars * 100);
    // counting the coins
    int z0 = cents % 25;
    int coins = (cents - z0) / 25;
    int z1 = z0 % 10;
    coins += (z0 - z1) / 10;
    z0 = z1 % 5;
    coins += (z1 - z0) / 5;
    coins += z0;
    printf("%d \n", coins);
}
