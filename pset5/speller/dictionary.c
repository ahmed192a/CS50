// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "dictionary.h"



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
unsigned int countw = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int ind = hash(word);

    if(table[ind] != NULL)
    {
        for (node *tmp = table[ind]; tmp != NULL; tmp = tmp->next)
        {
            if(strcasecmp(tmp->word, word) == 0)
            {
                //free(tmp);
                return true;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    if(word[0]>='a' && word[0]<='z')
    {
        return word[0] - 'a';
    }
    else if (word[0]>='A' && word[0]<='Z')
    {
        return word[0] - 'A';
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char nextw [LENGTH + 1];
    node *n = NULL;
    FILE *f = fopen(dictionary,"r");
    countw = 0;
    int ind=0;

    if (f == NULL)
    {
        free(n);
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }



    while(fscanf(f,"%s", nextw) != EOF)
    {
        countw++;
        n = malloc(sizeof(node));
        strcpy(n->word,nextw);
        ind = hash(nextw);
        n->next = table[ind];
        table[ind] = n;
        //printf("%s \n", table[ind]->word);

        //fscanf(f,"%s", nextw);
    }


    fclose(f);
    n = NULL;
    free(n);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return countw;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;
    node *temp = NULL;
    for (int i = 0; i < N; i++)
    {

        cursor = table[i];
        table[i] = NULL;

        while(cursor != NULL)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

    }
    for (int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
            return false;
    }

    return true;
}
