#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularQueue.h"

void init(CircularQ *Q) {
	
	int i;
	
	Q->front = 5;
	Q->rear = 4;
	for(i = 0; i < MAX; i++) {
		Q->data[i] = -1;
	}
}

bool isEmpty(CircularQ Q) {
	return ((Q.rear+1) % MAX == Q.front);
}

bool isFull(CircularQ Q) {
	return ((Q.rear+2) % MAX == Q.front);
}

void enqueue(CircularQ *Q, int elem) {
	
	if(isFull(*Q)) {
		printf("\nThe List is Full.\n\n");
	}
	else {
		Q->rear =  (Q->rear+1) % MAX;
		Q->data[Q->rear] = elem;
		printf("\nElement %d is enqueued.\n\n", elem);
	}
}

void dequeue(CircularQ *Q) {
	
	if(isEmpty(*Q)) {
		printf("\nThe List is Empty.\n\n");
	} 
	else {
		printf("\nElement %d is dequeued.\n\n", Q->data[Q->front]);
		Q->data[Q->front] = -1;
		Q->front = (Q->front+1) % MAX;
	}
}

void front(CircularQ Q) {
	printf("\nFRONT\n\nIndex: %d\nValue: %d\n\n", Q.front, Q.data[Q.front]);
}

void rear(CircularQ Q) {
	printf("\nREAR\n\nIndex: %d\nValue: %d\n\n", Q.rear, Q.data[Q.rear]);
}

void display(CircularQ Q) {
	
	int i;
	
	if(isEmpty(Q)) {
		printf("\nThe List is Empty.\n");
	}
	else {
		printf("LIST: ");
		for(i = 0; i < MAX; i++) {
			if(Q.data[i] != -1) {
				printf("%d ", Q.data[i]);
			} 
			else {
				printf("");
			}
		}
	}
	printf("\n");
}

