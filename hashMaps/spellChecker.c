/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: John Carrabino
 * Date: 11/20/2016
 */
#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    char* word = nextWord(file);
   
    while (word) {
       hashMapPut(map, word, 1);
       free(word);
       word = nextWord(file);
    }

    free(word);
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
    HashMap* map = hashMapNew(1000);
   
    printf("Opening dictionary.txt\n"); 
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    hashMapPrint(map);
    timer = clock() - timer;
    printf("%i Word Dictionary loaded in %f seconds\n", hashMapSize(map), (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    char wordAddAnswer[50];
    int quit = 0;
	int i = 0, len1 = 0, dist = 0;
    int wordAddBool = 0;
    while (!quit)
    {   

        printf("Enter a word or \"/quit\" to quit: ");
        scanf("%s", inputBuffer);

        // Implement the spell checker code here..
        if (hashMapContainsKey(map, inputBuffer)) {
            int idx = HASH_FUNCTION(inputBuffer) % hashMapCapacity(map);
            HashLink* cur = map->table[idx];
            printf("Did you mean...?\n");
			len1 = strlen(inputBuffer);
			if(len1 > 3){
				while (cur) {
				  // Filtering returned links to only print keys of links that have
				  // keys that begin with the same leading letter
				  dist = 0;
				  for(i = 0; i < len1; i++ ){
						if(cur->key[i] == '\0'){
							break;
						}
						if(inputBuffer[i] == cur->key[i]){
							dist++;
						}
				  }
				if(cur->key[0] == inputBuffer[0] && cur->key[len1-1] == inputBuffer[len1-1]
					&& cur->key[len1/2] == inputBuffer[len1/2]){
						printf("%s\n",cur->key);
				}
				else{		
				  for(i=len1; i > 1; i--){
					  if(dist == i){
						  if(cur->key[0] == inputBuffer[0])
							printf("%s\n",cur->key);
					  }
				  }
					
				}
				 
				  cur = cur->next;
			   }
			}
			else{
				if(inputBuffer[0] == cur->key[0]){
					printf("%s\n",cur->key);
				}
				cur = cur->next;
			}
        } else if (strcmp(inputBuffer, "/quit") == 0) {
           quit = 1;
        } else {
           printf("Word, %s, not found\n", inputBuffer);

           wordAddBool = 1;           

           while (wordAddBool) {
              printf("Would you like to add your word to the dictionary? y/n: ");
              scanf("%s", wordAddAnswer);
              wordAddBool = 0;
              if (strcmp(wordAddAnswer, "y") == 0) {
                 hashMapPut(map, inputBuffer, 1);
                 printf("Word added to dictionary\n");
              } else if (strcmp(wordAddAnswer, "n") == 0) {
                 printf("Word not added to dictionary\n");
              } else {
                 wordAddBool = 1;
              }
           }
        }
    }

    // Cleaned up the hashMap dictionary from the heap
    hashMapDelete(map);
    return 0;
}