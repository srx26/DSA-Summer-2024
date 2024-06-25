#include <stdio.h>
#include <stdlib.h>
#include "FCFSLL.h"

void init(NodePtr *L) {
	
	*L = NULL;
}

void addProcess(NodePtr *L, char id, Data bt, Data at, Data *c) {
	
	NodePtr temp = malloc(sizeof(Node));
	NodePtr nP = malloc(sizeof(Node));
	
	nP->info.processId = id;
	nP->info.BT = bt;
	nP->info.AT = at;
	
	if(*L == NULL) {
		nP->next = NULL;
		*L = nP;
		*c += 1;
	}
	else {
		
		for(; *L != NULL; L=&(*L)->next) {
			
			if(nP->info.AT < (*L)->info.AT) {
				nP->next = *L;
				*L = nP;
				break;
			}
			else if(nP->info.AT == (*L)->info.AT) {
				if(nP->info.processId < (*L)->info.processId) {
					nP->next = *L;
					*L = nP;
					break;
				}
				else {
					continue;
				}
			}
			else if(nP->info.AT > (*L)->info.AT) {
				continue;
			}
			if(*L == NULL) {
				nP->next = NULL;
				*L = nP;
			}
		}
		if(*L == NULL) {
			nP->next = NULL;
			*L = nP;
		}
		*c += 1;
	}
}

void display(NodePtr L) {
	
	NodePtr trav;
	
	printf("%s | %s | %s\n", "Process Id", "Burst Time", "Arrival Time");
	
	for(trav = L; trav != NULL; trav = trav->next) {
		printf("%10c | %10d | %12d\n", trav->info.processId, trav->info.BT, trav->info.AT);
	}
}

void displayTWT(NodePtr L, Data c) {
	
	Data i, tat = 0, wt = 0, ct = 0;
	NodePtr trav;
	float totalTAT = 0, totalWT = 0, avgTAT = 0, avgWT = 0;
	
	printf("%s | %s | %s | %s | %s | %s |\n", "Process Id", "Burst Time", "Arrival Time", "Completion Time", "Turnaround Time", "Waiting Time");
	
	for(i=1, trav = L; trav != NULL; i++, trav = trav->next) {
		if(i==1) {
			ct = L->info.BT + L->info.AT;
			tat = ct-trav->info.AT;
			wt = tat - trav->info.BT;
			printf("%10c | %10d | %12d | %15d | %15d | %12d |\n", trav->info.processId, trav->info.BT, trav->info.AT, ct, tat, wt);
			totalTAT += tat;
			totalWT += wt;
		}
		else {
			ct += trav->info.BT;
			tat = ct-trav->info.AT;
			wt = tat - trav->info.BT;
			printf("%10c | %10d | %12d | %15d | %15d | %12d |\n", trav->info.processId, trav->info.BT, trav->info.AT, ct, tat, wt);
			totalTAT += tat;
			totalWT += wt;
		}
	}
	printf("%10s | %10s   %12s   %15s | %15.2f | %12.2f |\n", "TOTAL", "", "", "", totalTAT, totalWT);
	
	avgTAT = totalTAT/c;
	avgWT = totalWT/c;
	
	printf("\nAverage Turnaround Time: %.2f", avgTAT);
	printf("\nAverage Waiting Time: %.2f\n", avgWT);
}


