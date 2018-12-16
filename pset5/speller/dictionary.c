// Implements a dictionary's functionality
#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct word
{
    char wordStr[LENGTH + 1];
    struct word* next;
}word;
word* wordHash[26];

//inserts word from dictionary into hash table
void insert(word* toBeInserted);


// Returns true if word is in dictionary else false
bool check(const char *toBeChecked)
{
    int index = tolower(toBeChecked[0]) - 'a';

    word* cursor = wordHash[index];
    while(cursor != NULL)
    {
        if (!strcasecmp(cursor->wordStr, toBeChecked))
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE* inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    char tempWord[LENGTH + 1];
    while(fscanf(inptr, "%s", tempWord) != EOF)
    {
        word* newWord = malloc(sizeof(word));
        if (newWord == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(newWord->wordStr, tempWord);
            insert(newWord);
        }
    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int count = 0;
    for(int i = 0; i < 26; i++)
    {
        word *cursor = wordHash[i];
        while(cursor!=NULL)
        {
            count++;
            cursor = cursor->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < 26; i++)
    {
        word *cursor = wordHash[i];
        while(cursor != NULL)
        {
            word *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}


//inserts word into the hash table
void insert(word* toBeInserted)
{
    //hash the node
    int index = tolower(toBeInserted->wordStr[0]) - 'a';
    //insert into the hashtable
    toBeInserted->next = wordHash[index];
    wordHash[index] = toBeInserted;
}