#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char change(char x, int y);
int check(int x,  int y);

int main(int argc, string argv[])
{
    //chaeck the user enter a key or not
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // check if the key has any letter
    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
            printf("Usage: ./caesar key #key shoud be number only\n");
            return 1;
        }
    }
    //  check limitaion of the key
    int shift =  atoi(argv[1]);
    if (check(argc, shift) == 0)
    {
        // get the input text
        string in = get_string("plaintext:  ");
        printf("ciphertext: ");
        // cipher the input
        for (int i = 0; i < strlen(in); i++)
        {
            char c = change(in[i], shift);
            printf("%c", c);
        }
        printf("\n");

    }
    else
    {
        return 1;
    }
    return 0;
}

int check(int x,  int y)
{
    // check if the key is empty
    if (y == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0 ;

}


char change(char x, int y)
{
    // check if the char is small
    if (x >= 'a' && x <= 'z')
    {
        // make sure that if it pass the 'z' to return from the begining 'a'
        if ((x + y) > 122)
        {
            x = x - 'a';
            x = x + y;
            y = (int) x / 26;
            x = x - y * 26;
            x = x + 'a';
            return x;

        }
        else
        {
            return x + y;
        }

    }
    // the char is capital
    else if (x >= 'A' && x <= 'Z')
    {
        // make sure that if it pass the 'Z' to return from the begining 'A'
        if ((x + y) > 90)
        {
            x = x - 'A';
            x = x + y;
            y = (int) x / 26;
            x = x - y * 26;
            x = x + 'A';
            return x;

        }
        else
        {
            return x + y;
        }

    }
    else
    {
        return x;
    }
}




