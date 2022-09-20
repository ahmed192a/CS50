#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int letters_num(string y);
int word_num(string x);
int sent_num(string x);
float avg(int x, int y);

int main(void)
{
    // get the text
    string in = get_string("Text: ");
    // parameters of the The Coleman-Liau index
    float L = avg(letters_num(in), word_num(in));
    float S = avg(sent_num(in),  word_num(in));
    //The Coleman-Liau index formula
    int G = round(0.0588 * L - 0.296 * S - 15.8);
    if (G >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (G < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", G);
    }
}


int letters_num(string y)
{
    //count the letters
    int count = 0;
    for (int i = 0 ; i < strlen(y); i++)
    {
        // check if the the char if alphabetical
        if ((y[i] >= 'a' && y[i] <= 'z') || (y[i] >= 'A' && y[i] <= 'Z'))
        {
            count += 1;
        }
    }
    return count;
}

int word_num(string x)
{
    //count the words
    int count = 0;
    for (int i = 0 ; i < strlen(x); i++)
    {
        // check if the the char if space
        if (x[i] == ' ')
        {
            count += 1;
        }
    }
    return count + 1;
}

int sent_num(string x)
{
    //count of the sentence
    int count = 0;
    for (int i = 0 ; i < strlen(x) ; i++)
    {
        // check the end of the sentance
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}

float avg(int x, int y)
{
    //get the average per 100 word
    return x * 100 / (float) y ;
}
