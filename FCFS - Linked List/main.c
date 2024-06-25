#include <stdio.h>
#include <stdlib.h>
#include "FCFSLL.h"

int main() {
	
	NodePtr list;
	Data opt, i, b, a, count = 0;
	char pId;
	String menu[20] = {"Add Processes", "Display", "Count", "Display w/ TaT & WT", "Exit"};
	
	init(&list);
	
	do {
		printf("MENU\n");
		for(i=0; i<5; i++) {
			printf("%d. %s\n", i+1, menu[i]);
		}
		printf("\nChoose an option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				
				printf("\nADD PROCESS\n\n");
				
				printf("Input Process Id: ");
				scanf(" %c", &pId);
				printf("Input Burst Time: ");
				scanf("%d", &b);
				printf("Input Arrival Time: ");
				scanf("%d", &a);
				
				addProcess(&list, pId, b, a, &count);
				
				system("pause");
				system("cls");
				break;
			case 2:
				printf("\nDISPLAY PROCESSES\n\n");
				display(list);
				
				system("pause");
				system("cls");
				break;
			case 3:
				printf("\nTotal Number of Processes: %d\n\n", count);
				
				system("pause");
				system("cls");
				break;
			case 4:
				printf("\nDISPLAY PROCESSES w/ TaT & WT\n\n");
				displayTWT(list, count);
				
				system("pause");
				system("cls");
				break;
			case 5:
				printf("\nYou have exited.\n");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
	} while(opt != 5);
	
	return 0;
}
