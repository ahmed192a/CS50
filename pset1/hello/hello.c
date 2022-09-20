#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask the user for his/her name
    string name = get_string("What is your name?\n");
    // say hello to the user
    printf("hello, %s \n", name);
}