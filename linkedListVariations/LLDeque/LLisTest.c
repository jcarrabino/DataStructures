#include "linkedList.h"
#include <stdio.h>

int main()
{	
	struct LinkedList* deque = linkedListCreate(); 
	linkedListAddBack(deque, (TYPE)1);
	linkedListAddBack(deque, (TYPE)2);
	linkedListAddBack(deque, (TYPE)3);
	linkedListAddBack(deque, (TYPE)4);
	linkedListAddBack(deque, (TYPE)5);
	linkedListAddBack(deque, (TYPE)6);
	linkedListPrint(deque);
	printf("Front = %d\n", linkedListFront(deque));
	printf("Back = %d\n", linkedListBack(deque));
	
	linkedListRemoveFront(deque);
	linkedListRemoveBack(deque);
	linkedListPrint(deque);
	
	linkedListDestroy(deque);
	
	return 0;
}
