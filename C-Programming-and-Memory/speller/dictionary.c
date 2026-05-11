#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"


typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;


// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;
node *table[N];  //hash tablosu
unsigned int word_count = 0;  //yüklenen kelime sayısı


bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while(cursor != NULL)
    {
        if(strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash_value = 0;
    for(int i=0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31 + tolower((unsigned char)word[i])) % N;
    }
    return hash_value;

}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }
    memset(table, 0, sizeof(table));
    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(n -> word, word);
        int index = hash(word);
        n -> next = table[index];
        table[index] = n;
        word_count++;
    }
    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}



bool unload(void)
{
    // TODO
    for(int i=0; i<N; i++)
    {
        node *cursor = table[i];
        while(cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
    }
    return true;
}
