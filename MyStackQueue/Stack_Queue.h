#ifndef STACK_QUEUE
#define STACK_QUEUE
#include <stdbool.h>

#define MAX 10

typedef struct node {
	int data;
	struct node * next;
}SLL, *SLLPtr;

typedef struct {
	SLLPtr front;
	SLLPtr rear;
} Queue;

void initQueue(Queue *Q);

void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
void displayFront(Queue Q);
void displayRear(Queue Q);
bool isEmpty(Queue Q);

#endif
