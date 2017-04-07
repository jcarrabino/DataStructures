/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: John Carrabino
 * Date: 11/20/2016
 */
#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    
    clock_t timer = clock();
    
    HashMap* map = hashMapNew(1000);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.
    // --- Concordance code ends here ---
    
	//opens file
	FILE *file = fopen(fileName, "r");
	if (!file)
	{
		printf("The file %s was not found\n.", fileName);
		return 0;
	}

	//start concordance by iterating through the file until 
	//word == NULL == EOF reached
    char* word = nextWord(file);

    while (word != NULL) {
        hashMapPut(map, word, 1);
        free(word);
        word = nextWord(file);
    }
	free(word);
 
    int hashMapCap = hashMapCapacity(map);

    // Invoking concordance print method
    for (int i = 0; i < hashMapCap; i++) {
       HashLink* cur = map->table[i];
       if (cur != NULL) {
          while (cur) {
             printf("%s: %d\n", cur->key, cur->value);
             cur = cur->next;
          }
       }
    }
	
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
	//close file
	fclose(file);
    hashMapDelete(map);
    return 0;
}