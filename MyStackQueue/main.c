#include <stdio.h>
#include <stdlib.h>
#include "Stack_QUEUE.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Queue q;
	
	initQueue(&q);
	enqueue(&q, 1);
	displayFront(q);
	displayRear(q);
	
	enqueue(&q, 2);
	displayFront(q);
	displayRear(q);
	
	enqueue(&q, 5);
	displayFront(q);
	displayRear(q);
	
	enqueue(&q, 11);
	displayFront(q);
	displayRear(q);
	
	
	dequeue(&q);
	displayFront(q);
	displayRear(q);
	
	return 0;
}
