/* CS261- Assignment 3 - circularList.c*/
/* Name: John Carrabino
* Date: 10/16/2016
* Solution description: For this class my group and I
were able to reuse/translate functions we had written 
previously for CS162 in order to implement the circularList
class in C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	list->sentinel = malloc(sizeof(struct Link));
	assert(list->sentinel != 0);
	list->sentinel->next = list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
	assert (newLink != 0);
	newLink -> value = value;
	newLink->next = newLink->prev = newLink;
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	struct Link *newLink = createLink(value);
	if(list->size == 0){
		list->sentinel->next = newLink;
		list->sentinel->prev = newLink;
		newLink->next = list->sentinel;
		newLink->prev = list->sentinel;
		list->size++;

	}else{
		newLink->next = link->next;
		newLink->prev = link;
		link->next->prev = newLink;
		link->next = newLink;
		list->size++;
	}
	
	
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	link -> prev -> next = link -> next;
	link -> next -> prev = link -> prev;
	free (link);
	list -> size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	struct Link *newLink = list->sentinel->next;
	while (list->size > 0)
	{
		struct Link *garbage = newLink;
		newLink = newLink->next;
		removeLink(list,garbage);
	}
	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	addLinkAfter(list,list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	TYPE val = list->sentinel->next->value;
	return val;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	TYPE val = list->sentinel->prev->value;
	return val;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	assert(!circularListIsEmpty(list));
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	assert(!circularListIsEmpty(list));
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	return list->size == 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	assert(! circularListIsEmpty(list));
	struct Link *newLink = list->sentinel->next;
	do{
		printf("%f \n", newLink->value);
		newLink = newLink->next;
	}while(newLink != list->sentinel);
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	assert(! circularListIsEmpty(list));
	struct Link *current = list->sentinel;
	struct Link *next = current->next;
	struct Link *prev = current->prev;
	
	do{
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
		next = next->next;
		
	} while(current != list->sentinel);
}
