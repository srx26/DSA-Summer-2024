#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularQueue.h"

int main() {
	
	int opt, val, i;
	CircularQ list;
	String menuOpt[6] = {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Exit"};
	
	init(&list);
	
	do {
		
		printf("MENU\n");
		for(i = 0; i < 6; i++) {
			printf("%d. %s\n", i+1, menuOpt[i]);
		}
		printf("\nChoose an option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				
				printf("\nEnter a value: ");
				scanf("%d", &val);
				
				enqueue(&list, val);
				
				system("pause");
				system("cls");
				break;
			case 2:
				
				dequeue(&list);
				
				system("pause");
				system("cls");
				break;
			case 3:
				
				front(list);
				
				system("pause");
				system("cls");
				break;
			case 4:
				
				rear(list);
				
				system("pause");
				system("cls");
				break;
			case 5:
				
				display(list);
				
				system("pause");
				system("cls");
				break;
			case 6:
				printf("\nYou have exited.");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
	} while(opt != 6);
		
	return 0;
}
