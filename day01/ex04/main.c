#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_queue *q1;
	struct s_queue *q2;

	q1 = queueInit();
	q2 = queueInit();
	enqueue(q1, "first");
	enqueue(q1, "second");
	enqueue(q1, "last");
	enqueue(NULL, "first");
	printf("first - %s\n", q1->first->message);
	printf("last - %s\n", q1->last->message);
	printf("dequeue - %s\n", dequeue(q1));
	printf("first after dequeue - %s\n", q1->first->message);
	printf("dequeue for empty queue - %s\n", dequeue(q2));
	printf("dequeue for NULL - %s\n", dequeue(NULL));
	printf("peek - %s\n", peek(q1));
	printf("first after peek - %s\n", q1->first->message);
	printf("peek for empty queue - %s\n", peek(q2));
	printf("peek for NULL - %s\n", peek(NULL));
	printf("isEmpty - %d\n", isEmpty(q1));
	printf("isEmpty for empty queue - %d\n", isEmpty(q2));
	printf("isEmpty for NULL - %d\n", isEmpty(NULL));
	return (0);
}

// Function used for the test
// Don't go further :)

