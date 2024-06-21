#include <stdio.h>
#include <stdlib.h>
#include "MySet.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int opt, val, i;
	char setOpt;
	String menu[10] = {"Add Value", "Delete Value", "Find Union", "Find Intersection", "Display", "Exit"};
	DATA X, Y;
	
	init(&X);
	init(&Y);
	
	do {
		printf("MENU\n");
		for(i=0; i<6; i++) {
			printf("%d. %s\n", i+1, menu[i]);
		}
		printf("\nChoose an option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				system("cls");
				printf("ADD VALUE\n");
				printf("Select a Set (X/Y): ");
				scanf(" %c", &setOpt);
				
				switch(setOpt) {
					case 'X':
					case 'x':
						printf("Enter a value: ");
						scanf("%d", &val);
						addVal(&X, val);
						break;
					case 'Y':
					case 'y':
						printf("Enter a value: ");
						scanf("%d", &val);
						addVal(&Y, val);
						break;
				}

				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("DELETE VALUE\n");
				printf("Select a Set (X/Y): ");
				scanf(" %c", &setOpt);
				
				switch(setOpt) {
					case 'X':
					case 'x':
						printf("Enter an index: ");
						scanf("%d", &val);
						delVal(&X, val);
						break;
					case 'Y':
					case 'y':
						printf("Enter an index: ");
						scanf("%d", &val);
						delVal(&Y, val);
						break;
				}
				
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf("FIND UNION\n");
				printf("\nXuY: ");
				findUnion(X,Y);
				
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				printf("FIND INTERSECTION\n");
				printf("\nXnY: ");
				findIntersection(X,Y);
				
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				printf("Set X: ");
				display(X);
				printf("Set Y: ");
				display(Y);
				
				system("pause");
				system("cls");
				break;
			case 6:
				printf("\nYou have exited.\n");
				
				system("pause");
				system("cls");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
	} while(opt != 6);
	
	return 0;
}
