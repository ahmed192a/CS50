#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
char change(char x, string y);
int check(int x, string y);
int main(int argc, string argv[])
{
    // check the key
    if (check(argc, argv[1]) == 0)
    {
        // get the text
        string in = get_string("plaintext:  ");
        printf("ciphertext: ");
        // cipher the text
        for (int i = 0; i < strlen(in); i++)
        {
            char c = change(in[i], argv[1]);
            printf("%c", c);
        }
        printf("\n");
    }
    else
    {
        return 1;
    }
}

char change(char x, string y)
{
    // substitute
    // char is lowercase
    if (x >= 'a' && x <= 'z')
    {
        int x1 = x - 'a';
        if (isupper(y[x1]))
        {
            return y[x1] + 32;
        }
        else
        {
            return y[x1];
        }
    }
    // char uppercase
    else if (x >= 'A' && x <= 'Z')
    {
        int x1 = x - 'A';
        if (isupper(y[x1]))
        {
            return y[x1];
        }
        else
        {
            return y[x1] - 32;
        }
    }
    // char is not substitution char
    else
    {
        return x;
    }
}

int check(int x, string y)
{
    //handles lack of key
    if (x == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //handles invalid key length
    else if (strlen(y) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //handles invalid characters in key
    for (int i = 0; i < strlen(y); i++)
    {
        if ((y[i] >= 'a' && y[i] <= 'z') || (y[i] >= 'A' && y[i] <= 'Z'))
        {
            continue;
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
            break;
        }
    }


    // check if repeated char
    for (int i = 0; i < strlen(y); i++)
    {
        for (int j = i + 1; j < strlen(y); j++)
        {
            if (tolower(y[i]) == tolower(y[j]))
            {
                printf("Key must contain 26 characters.\n");
                return 1;
                break;
            }
        }
    }


    return 0;
}