#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void addProcess(Process *L) {
	
	int i;
	
	for(i=0; i<MAX; i++) {
		system("cls");
		printf("ADD PROCESSES\n\n");
		printf("Input process ID: ");
		scanf(" %c", &L->list[i].pId);
		printf("Input Burst Time: ");
		scanf("%d", &L->list[i].time.BT);
		printf("Input Arrival Time: ");
		scanf("%d", &L->list[i].time.AT);
	}				
	
}

void display(Process L) {
	
	int i;
	
	printf("%15s\t%15s\t%15s\n", "Process ID", "Burst Time", "Arrival Time");
	
	for(i=0; i<MAX; i++) {
		printf("%15c\t%15d\t%15d\n", L.list[i].pId, L.list[i].time.BT, L.list[i].time.AT);
	}
}
