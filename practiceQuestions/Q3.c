/* CS261- Assignment 1 - Q.3*/
/* Name:
* Date:
* Solution description:
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n) {

	/*Sort the given array number , of length n*/
	int i, j, temp;
	for (i = 0; i < (n - 1); i++) {
		for (j = 0; j < (n - 1); j++) {
			if (number[j] > number[j + 1]) {
				temp = number[j + 1];
				number[j + 1] = number[j];
				number[j] = temp;
			}
		}
	}
	return;
}

int main() {
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	/*Allocate memory for an array of n integers using malloc.*/
	int *array = malloc(n * sizeof(int));
	/*Fill this array with random numbers, using rand().*/
	srand(time(NULL));
	int i = 0;
	for (i; i < n; i++) {
		array[i] = rand() % 100 + 1;
	}
	/*Print the contents of the array.*/
	printf("The array contains the following numbers: \n\n");
	for (i = 0; i < n; i++) {
		printf("%d \n", array[i]);
	}
	/*Pass this array along with n to the sort() function of part a.*/
	sort(array, n);
	/*Print the contents of the array.*/
	printf("\n\nThe array NOW contains the following numbers: \n\n");
	for (i = 0; i < n; i++) {
		printf("%d \n", array[i]);
	}
	printf("\n\nPress ENTER to continue");
	char ch = getchar();
	return 0;
}