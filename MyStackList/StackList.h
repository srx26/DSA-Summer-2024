#ifndef STACK_LIST
#define STACK_LIST
#include <stdbool.h>

typedef struct node {
	int data;
	struct node * next;
}Node, *NodePtr;

void initStack(NodePtr *head);
bool isEmpty(NodePtr head);
void push(NodePtr *head, int elem);
void pop(NodePtr *head);
int peek(NodePtr head);
void display(NodePtr head);
void visualize(NodePtr head);

#endif
