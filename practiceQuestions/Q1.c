/* CS261- Assignment 1 - Q.1*/
/* Name:
* Date:
* Solution description:
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/

	/*return the pointer*/

	struct student* std = malloc(10 * sizeof(struct student));
	return std;
}

void generate(struct student* students) {
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int x, y, z, r;
	int ids[] = { 1,2,3,4,5,6,7,8,9,10 };
	int ary[10] = { 0 };

	for (y = 0; y < 10; y++) {
		r = rand() % 10 + 1;
		for (z = 0; z < 10; z++) {
			if (r == ids[z]) {
				ids[z] = 0;
				ary[y] = r;
				break;
			}
			if (z == 9) {
				r = rand() % 10 + 1;
				z = 0;
			}
		}
	}

	for (x = 0; x < 10; x++) {
		students[x].id = ary[x];
		students[x].score = rand() % 100 + 0;
	}

	return;
}

void output(struct student* students) {
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/
	printf("The students IDs and Scores are as follows:\n\n");
	int i;
	for ( i = 0; i < 10; i++) {
		printf("Student ID: %d, Score: %d\n", students[i].id, students[i].score);
	}
	return;
}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = 10, max = 1, sum = 0;
	double avg;
	int i;
	for ( i = 0; i < 10; i++) {
		if (students[i].score >= max)
			max = students[i].score;
		if (students[i].score <= min)
			min = students[i].score;

		sum += students[i].score;
	}

	avg = sum / 10.0;

	printf("\nMin Score: %d \nMax Score: %d \nAverage Score: %lf", min, max, avg);

	return;
}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/

	free(stud);

}

int main() {
	struct student* stud = NULL;
	srand(time(NULL));
	/*call allocate*/
	stud = allocate();
	/*call generate*/
	generate(stud);
	/*call output*/
	output(stud);
	/*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);

	printf("\n\nPress ENTER to continue\n\n");
	char c = getchar();
	return 0;
}
