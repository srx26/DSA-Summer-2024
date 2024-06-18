#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#define MAX 10

typedef char String[30];

typedef struct {
	int data[MAX];
	int front;
	int rear;
}CircularQ;

void init(CircularQ *Q);
bool isEmpty(CircularQ Q);
bool isFull(CircularQ Q);
void enqueue(CircularQ *Q, int elem);
void dequeue(CircularQ *Q);
void front(CircularQ Q);
void rear(CircularQ Q);
void display(CircularQ Q);

#endif
