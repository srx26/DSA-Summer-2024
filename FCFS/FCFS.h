#ifndef FCFS_H
#define FCFS_H

#define MAX 5
#define Data int

typedef char String[30];

typedef struct {
	Data BT;
	Data AT;
}info;

typedef struct {
	char pId;
	info time;
}procId;

typedef struct {
	procId list[MAX];
}Process;

void addProcess(Process *L);
void display(Process L);

#endif
