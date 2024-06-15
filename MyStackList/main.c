#include <stdio.h>
#include <stdlib.h>
#include "StackList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	NodePtr list;
	int value, opt, peekTop;
	
	initStack(&list);
	
	do {
		printf("MENU");
		printf("\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Visualize \n6. Exit\n\n");
		printf("Choose an option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				printf("\nEnter value to push: ");
				scanf("%d", &value);
				push(&list, value);
				
				system("pause");
				system("cls");
				break;
			case 2:
				pop(&list);
				
				system("pause");
				system("cls");
				break;
			case 3:
				peekTop = peek(list);
				printf("\nTop of the Stack is: %d\n\n", peekTop);
				
				system("pause");
				system("cls");
				break;
			case 4:
				display(list);
				
				system("pause");
				system("cls");
				break;
			case 5:
				visualize(list);
				
				system("pause");
				system("cls");
				break;
			case 6:
				printf("You have exited.\n");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
		
	} while(opt != 6);
	
	return 0;
}
