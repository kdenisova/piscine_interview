#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	int arr[] = {10, -2, 2, 21, -5, 42, 3, -6, 17, 11};
	int n;
	int k;
	struct s_max *res;

	res = NULL;
	n = 10;
	k = 4;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	/*-------------------
	launch your test here
	--------------------*/

	//maxSlidingWindow(arr, n, k);
	// struct s_deque *deque;

	// deque = dequeInit();
	// pushBack(deque, 3);
	// pushFront(deque, 1);
	// pushBack(deque, 4);
	// // pushFront(deque, 2);
	// printf("%d\n", deque->first->value);
	// printf("%d\n", deque->first->next->value);
	// printf("%d\n", deque->last->value);
	// printf("%d\n", deque->last->prev->value);
	
	// printf("\n%d\n", popFront(deque));
	// printf("%d\n", deque->first->value);
	// printf("%d\n", deque->last->prev->value);
	// pushFront(deque, 2);
	// printf("\n%d\n", popBack(deque));
	// printf("%d\n", deque->first->value);
	// printf("%d\n", deque->last->value);
	// printf("%d\n", deque->last->prev->value);
	res = maxSlidingWindow(arr, n, k);
	if (res) {
		for (int i = 0; i < res->length; i++)
			printf("%d ", res->max[i]);
		printf("\n");
	}

	return (0);
}



// Function used for the test
// Don't go further :)

