#ifndef FCFSLL_H
#define FCFSLL_H

typedef int Data;
typedef char String[50];

typedef struct {
	char processId;
	Data BT;
	Data AT;
}Process;

typedef struct node {
	Process info;
	struct node * next;
}Node, *NodePtr;

void init(NodePtr *L);
void addProcess(NodePtr *L, char id, Data bt, Data at, Data *c);
void display(NodePtr L);
void displayTWT(NodePtr L, Data c);

#endif
