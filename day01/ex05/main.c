#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 90);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);
	tankPush(tank, 50);
	printf("push 50  energy in %d stack\n", tank->n);
	tankPush(tank, 100);
	printf("push 100 energy in %d stack\n", tank->n);

	printf("\npop %d energy, active stack %d\n", tankPop(tank), tank->n);
	printf("pop %d energy, active stack %d\n", tankPop(tank), tank->n);
	printf("pop %d energy, active stack %d\n", tankPop(tank), tank->n);
	printf("pop %d energy, active stack %d\n", tankPop(tank), tank->n);
	return (0);
}



// Function used for the test
// Don't go further :)
