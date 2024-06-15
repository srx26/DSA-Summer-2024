#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack_Queue.h"

void initQueue(Queue *Q) {
	
	Q->front = NULL;
	Q->rear = NULL;
}

void enqueue(Queue *Q, int elem) {
	
	SLLPtr nD = malloc(sizeof(SLL)); 
	
	if(isEmpty(*Q) == 0) {
		
		nD->data = elem;
		nD->next = NULL;
		
		Q->front = nD;
		Q->rear = nD;
	}
	else {
		nD->data = elem;
		nD->next = NULL;
		
		Q->rear->next = nD;
		Q->rear = nD;
	}
}

void dequeue(Queue *Q) {
	
	SLLPtr temp = malloc(sizeof(SLL));
	
	temp = Q->front;
	Q->front = temp->next;
	free(temp);
}

void displayFront(Queue Q) {
	
	printf("\n\nFront: %d", Q.front->data);
}

void displayRear(Queue Q) {
	
	printf("\nRear: %d", Q.rear->data);
}

bool isEmpty(Queue Q) {
	
	if(Q.front == NULL && Q.rear == NULL) {
		printf("\nThe List is empty.\n");
		return 0;
	}
	else {
		return 1;
	}
}

