#include "listADT.h"
#include <stdio.h>

int main()
{	
	printf("Now testing linked list: \n");
	struct LinkedList* list = linkedListCreate();
	linkedListAddBack(list, (TYPE)1);
	linkedListAddBack(list, (TYPE)2);
	linkedListAddBack(list, (TYPE)3);
	linkedListAddFront(list, (TYPE)4);
	linkedListAddFront(list, (TYPE)5);
	linkedListAddFront(list, (TYPE)6);
	linkedListPrint(list);
	printf("\nFront of List: ");
	printf("%i\n", linkedListFront(list));
	printf("\nBack of List: ");
	printf("%i\n", linkedListBack(list));
	
	linkedListRemoveFront(list);
	linkedListRemoveBack(list);
	linkedListPrint(list);
		
	linkedListDestroy(list);
	
	printf("Now testing Circular Linked List: \n");
	struct CircularList* deque = circularListCreate(); 
	circularListAddBack(deque, (TYPE)1);
	circularListAddBack(deque, (TYPE)2);
	circularListAddBack(deque, (TYPE)3);
	circularListAddFront(deque, (TYPE)4);
	circularListAddFront(deque, (TYPE)5);
	circularListAddFront(deque, (TYPE)6);
	circularListPrint(deque);
	printf("\nFront of Queue: ");
	printf("%i\n", circularListFront(deque));
	printf("\nBack of Queue: ");
	printf("%i\n", circularListBack(deque));
	
	circularListRemoveFront(deque);
	circularListRemoveBack(deque);
	circularListPrint(deque);
	
	circularListReverse(deque);
	circularListPrint(deque);
	
	circularListDestroy(deque);
	
	return 0;
}
