#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main() {
	
	Process list;
	Data opt, i, bt, at;
	char id;
	String menu[20] = {"Add Processes", "Display", "Exit"};
	
	do {
		printf("MENU\n");
		for(i=0; i<3; i++) {
			printf("%d. %s\n", i+1, menu[i]);
		}
		printf("\nChoose an option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				addProcess(&list);
				
				system("pause");
				system("cls");
				break;
			case 2:
				printf("DISPLAY PROCESSES\n\n");
				display(list);
				
				system("pause");
				system("cls");
				break;
			case 3:
				printf("\nYou have exited.\n");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
	} while(opt != 3);
	
	return 0;
}
