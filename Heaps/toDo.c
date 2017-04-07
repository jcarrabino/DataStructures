/*
 * CS 261 Assignment 5
 * Name: John Carrabino	
 * Date: 11/13/2016
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
	FILE *outputFile = NULL;
	char file[256];
	char name[256];
	int pLevel;
	Task* newTask = malloc(sizeof(Task));
	
    if(command == 'l' || command == 'L'){
		printf("\nEnter the name of the file you wish to open: ");
		scanf("%254s", file);
		while (getchar() != '\n');
		printf("\n");
		
		if((strlen(file) > 0 && (file[strlen(file)-1] == '\n')))
			file[strlen(file)-1] = '\0';
		
		outputFile = fopen(file, "r");
		if(outputFile == NULL){
			fprintf(stderr, "Cannot open %s\n\n", file);
			return;
		}
		
		else{
			listLoad(list, outputFile);
			fclose(outputFile);
			printf("\nFile \"%s\" has been successfully loaded\n\n",file);
			return;
		}
			
		
	}
	else if(command == 's' || command == 'S'){
		printf("\nEnter the name of the file you wish to save to: ");
		scanf("%254s", file);
		while (getchar() != '\n');
		printf("\n");
		
		if((strlen(file) > 0 && (file[strlen(file)-1] == '\n')))
			file[strlen(file)-1] = '\0';
		
		outputFile = fopen(file, "w");
		if(outputFile == NULL){
			fprintf(stderr, "Cannot open %s\n\n", file);
			return;
		}
		
		else{
			listSave(list, outputFile);
			fclose(outputFile);
			
			printf("File \"%s\" has been saved\n\n", file);
			return;
		}
	}
	else if(command == 'a' || command == 'A'){
		printf("\nPriority level: ");
		scanf("%i", &pLevel);
		while (getchar() != '\n');
		
		printf("\nTask name: ");
		scanf ("%[^\n]s", name);
		while (getchar() != '\n');
		
		newTask = taskNew(pLevel, name);
		dyOrderedAdd(list, newTask, taskCompare);
		printf("\nTask number %i has been added\n\n", pLevel);
		return;
		
		
	}
	else if(command == 'g' || command == 'G'){
		if(dySize(list) == 0){
			printf("\nYour todo list is empty!\n\n");
			return;
		}
		else{
			printf("\n");
			taskPrint(dyHeapGetMin(list));
			printf("\n\n");
			return;
		}
		
	}
	else if(command == 'r' || command == 'R'){
		if(dySize(list) == 0){
			printf("\nYour todo list is empty!\n\n");
			return;
		}
		else{
			printf("Task succesfully removed");
			dyHeapRemoveMin(list,taskCompare);
			printf("\n\n");
			return;
		}
		
	}
	else if(command == 'p' || command == 'P'){
		printf("\nCurrent ToDo List: \n");
		listPrint(list);
		printf("\n\n");
		return;
	}
	else if(command == 'e' || command == 'E'){
		printf("\nGoodbye!\n\n");
		return;
	}
	else{
		printf("\nPlease enter a valid command!\n\n");
		return;
	}
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}