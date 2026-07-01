/*
	Course:		CS106L PDS Lab 
	Semester:	2026 Jan-May
	Lab:		05 | Set ADT on Sorted Link List Data Structure
	Task Set 2:	Set ADT using Sorted Link List Data Structures

	Aim: 		Implement a set ADT over sorted linked list with the functions to
				a)	create an empty set (= empty list = null pointer)
				b)	add an element to a set
				c)	remove an element to a set
				d)	create a new set as the union of two given sets
				e)	create a new set as the intersection of two given sets
				f)	create a new set as the set difference of two given sets
				
	Assume:		All data to be stored are integers
*/

#include <limits.h>	// For INT_MAX
#include <stdio.h>
#include <stdlib.h>	// Needed for malloc, free etc
#include "sorted-ll.h"

typedef sortedLL set;		// A set is a sorted LL under the hood 

void print_set(set* S) {
/*
	Input:	A set
	Actions:
		Prints the numbers in the set in the format {2, 3, 5}
*/
	printf("{");
	while(S != NULL) {
		printf("%d", S->data);
		if(S->next != NULL)
			printf(", ");
		S = S->next;
	}
	printf("}\n");
	return;
}

set* empty_set() {
	return NULL;
}

void free_set(set *S) {
	delete_list(S);
}

/* Task 3. 
	Implement a function to add a new item to a set
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error response have to be as in the comments below.
*/
set* add(int item, set* S) {
/*
	Inputs:
		1. 	An integer
		2.	A set
	Actions:
		1.	Using the find() function of the sorted LL, check if the item is already
			in the list.
		2.	If the item is already in the set, then nothing is changed and the
			original set pointer is returned.
		3.	If the item is not in the list, it is added to the list (using the
			insert() funciton of the sorted LL. The head of the new list is
			returned. (The head will be different from the input list only if
			the added item is the new smallest item)
*/
	if (find(item, S) == -1) {
		S = insert(item, S);
	}
	return S;
}

/* Task 4. 
	Implement a function to remove an item from a set
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error response have to be as in the comments below.
*/
set* rem(int item, set* S) { // the name remove is already used by a funciton in stdio.h
/*
	Inputs:
		1. 	An integer
		2.	A set
	Actions:
		1.	Using the find() function of the sorted LL, check if the item is already
			in the list.
		2.	If the item is already in the set, then remove it using the delete()
			function of the sorted LL.
		3.	If the item is not in the list do nothing and return the original
			set pointer is returned.
*/
	if (find(item, S) != -1) {
		S = delete(item, S);
	}
	return S;
}

/* Task 5. 
	Implement a function to take two sets and return a new set which is the
	union of the two given sets
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error response have to be as in the comments below.
*/
set* uni(set* S, set* T) { // the name union is a reserved keyword
    set *U = empty_set();

    // Traverse both lists
    while (S != NULL && T != NULL) {

        if (S->data < T->data) {
            U = insert(S->data, U);
            S = S->next;
        }
        else if (S->data > T->data) {
            U = insert(T->data, U);
            T = T->next;
        }
        else { // equal elements (avoid duplicate)
            U = insert(S->data, U);
            S = S->next;
            T = T->next;
        }
    }

    // Add remaining elements of S
    while (S != NULL) {
        U = insert(S->data, U);
        S = S->next;
    }

    // Add remaining elements of T
    while (T != NULL) {
        U = insert(T->data, U);
        T = T->next;
    }

    return U;
}


/* Task 6. 
	Implement a function to take two sets and return a new set which is the
	intersection of the two given sets
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error response have to be as in the comments below.
*/
set* inter(set* S, set* T) { // the name int is a reserved keyword
	 set *U = empty_set();

    // Traverse both lists
    while (S != NULL && T != NULL) {

        if (S->data < T->data) {
            S = S->next;
        }
        else if (S->data > T->data) {
            T = T->next;
        }
        else { // equal elements
            U = insert(S->data, U);
            S = S->next;
            T = T->next;
        }
    }
/*
	Inputs:
		1. 	Two sets S and T
	Actions:
		2.	Create an empty set U and carefully add the common items from S and
			T to U ensuring that
			a)	U is in sorted order
			b)	U does not contain any duplicate item
			c)	The total operation takes only O(n) time. 
				This means you create U in order (without needing any insert 
				in the middle)
*/

	return U;
}

/* Task 7. 
	Implement a function to take two sets S and T and return a new set which
	is the S - T (all elements in S but not in T)
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error response have to be as in the comments below.
*/
set* diff(set* S, set* T) { 
/*
	Inputs:
		1. 	Two sets S and T
	Actions:
		2.	Create an empty set U and carefully add the common items from S and
			T to U ensuring that
			a)	U is in sorted order
			b)	U does not contain any duplicate item
			c)	The total operation takes only O(n) time. 
				This means you create U in order (without needing any insert 
				in the middle)
*/
	set *U = empty_set();
	// Task  7 Solution
	// Traverse both lists
    while (S != NULL && T != NULL) {

        if (S->data < T->data) {
            U = insert(S->data, U);
            S = S->next;
        }
        else if (S->data > T->data) {
            T = T->next;
        }
        else { // equal → skip
            S = S->next;
            T = T->next;
        }
    }

    // Add remaining elements of S
    while (S != NULL) {
        U = insert(S->data, U);
        S = S->next;
    }

	return U;
}

/* Task 8 
	Implement a function to take two sets S and T and return a new set which
	is the S XOR T (all elements in exactly one of the two) 
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error response have to be as in the comments below.
*/
set* simdiff(set* S, set* T) { 
/*
	Inputs:
		1. 	Two sets S and T
	Actions:
		2.	Create an empty set U and carefully add the common items from S and
			T to U ensuring that
			a)	U is in sorted order
			b)	U does not contain any duplicate item
			c)	The total operation takes only O(n) time. 
				This means you create U in order (without needing any insert 
				in the middle)
*/
	set *U = empty_set();
	// Task  8 Solution
	while (S != NULL && T != NULL) {

        if (S->data < T->data) {
            U = insert(S->data, U);
            S = S->next;
        }
        else if (S->data > T->data) {
            U = insert(T->data, U);
            T = T->next;
        }
        else { // equal → skip
            S = S->next;
            T = T->next;
        }
    }

    // Remaining elements
    while (S != NULL) {
        U = insert(S->data, U);
        S = S->next;
    }

    while (T != NULL) {
        U = insert(T->data, U);
        T = T->next;
    }

	return U;
}



/* 	All the testing for the tasks are included in the main. 
	Uncomment them one by one after you code the corresponding tasks in order.
*/
int main() {
	int i;
	set *S;

	// Test for Inital Setup
	printf("Creating an empty set ...\n");
	printf("-----------------------------\n\n");
	S = empty_set();
	print_set(S);

	// Test for Task 3
	printf("Testing Task 3 : add()\n");
	printf("-----------------------------\n\n");
	for(i = 5; i < 10; i++) {
		printf("Adding %d ...\n", i);
		S = add(i, S);
		print_set(S);
	}	
	for(i = 0; i < 7; i++) {
		printf("Adding %d ...\n", i);
		S = add(i, S);
		print_set(S);
	}	
	printf("============================\n\n");

	// Test for Task 4: delete()
	printf("Testing Task 4: rem()\n");
	printf("-----------------------------\n\n");
	print_set(S);
	for(i = 0; i < 13; i += 3) {
		printf("Removing %d ...\n", i);
		S = rem(i, S);
		print_set(S);
	}
	printf("============================\n\n");
	// Test for Task 5: union()
printf("Testing Task 5: union()\n");
printf("---------------------------------\n\n");

set *A = empty_set();
set *B = empty_set();
set *U;

// Create first set A
for(i = 0; i < 7; i++) {
    A = add(i, A);
}

// Create second set B
for(i = 5; i < 10; i++) {
    B = add(i, B);
}

printf("Set A: ");
print_set(A);

printf("Set B: ");
print_set(B);

// Perform union
U = uni(A, B);

printf("Union: ");
print_set(U);
// Test for Task 6: intersection()
printf("Testing Task 6: intersection()\n");
printf("---------------------------------\n\n");

set *I;

// Using same sets A and B
printf("Set A: ");
print_set(A);

printf("Set B: ");
print_set(B);

// Perform intersection
I = inter(A, B);

printf("Intersection: ");
print_set(I);

printf("=================================\n\n");

printf("=================================\n\n");
// Test for Task 7: difference()
printf("Testing Task 7: difference()\n");
printf("---------------------------------\n\n");

set *D;

// S - T (A - B)
printf("Set A: ");
print_set(A);

printf("Set B: ");
print_set(B);

// Perform difference
D = diff(A, B);

printf("Difference (A - B): ");
print_set(D);

printf("=================================\n\n");
// Test for Task 8: symmetric difference()
printf("Testing Task 8: symmetric difference()\n");
printf("---------------------------------\n\n");

set *SD;

printf("Set A: ");
print_set(A);

printf("Set B: ");
print_set(B);

// Perform symmetric difference
SD = simdiff(A, B);

printf("Symmetric Difference: ");
print_set(SD);

printf("=================================\n\n");
    




	free_set(S);
	return 0;
}