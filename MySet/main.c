#include <stdio.h>
#include <stdlib.h>
#include "MySet.h"

int main() {
	
	int opt, val, i, res;
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
				
				do {
					printf("ADD VALUE\n");
					printf("\nSelect a Set (X/Y): ");
					scanf(" %c", &setOpt);
					system("cls");
				} while(setOpt != 'X' && setOpt != 'x' && setOpt != 'Y' && setOpt != 'y');
				
				switch(setOpt) {
					case 'X':
					case 'x':
						if(X.count < MAX-1) {
							printf("ADD VALUE (X)\n");
							printf("Maximum of five values.\n\nEnter a value (1-9): ");
							for(i=0; i<MAX; i++) {
								scanf("%d", &val);
								addVal(&X, val);
							}
						}
						else {
							printf("Array is full.\n\n");
						}
						break;
					case 'Y':
					case 'y':
						if(Y.count < MAX-1) {
							printf("ADD VALUE (Y)\n");
							printf("Maximum of five values.\n\nEnter a value (1-9): ");
							for(i=0; i<MAX; i++) {
								scanf("%d", &val);
								addVal(&Y, val);
							}
						}
						else {
							printf("Array is full.\n\n");
						}
						break;
				}

				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				
				do {
					printf("DELETE VALUE\n");
					printf("\nSelect a Set (X/Y): ");
					scanf(" %c", &setOpt);
					system("cls");
				} while(setOpt != 'X' && setOpt != 'x' && setOpt != 'Y' && setOpt != 'y');
				
				switch(setOpt) {
					case 'X':
					case 'x':
						printf("DELETE VALUE (X)\n");
						printf("\nEnter an index: ");
						scanf("%d", &val);
						res = delVal(&X, val);
						break;
					case 'Y':
					case 'y':
						printf("DELETE VALUE (Y)\n");
						printf("\nEnter an index: ");
						scanf("%d", &val);
						res = delVal(&Y, val);
						break;
				}
				if(res) {
					printf("\nIndex %d is deleted.\n", val);
				}
				else {
					printf("\nIndex %d has no value.\n", val);
				}
				
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf("FIND UNION\n");
				printf("\nXuY: ");
				findUnion(X,Y);
				printf("\n");
				
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				printf("FIND INTERSECTION\n");
				printf("\nXnY: ");
				findIntersection(X,Y);
				printf("\n");
				
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				printf("Set X: ");
				display(X);
				printf("\n");
				printf("Set Y: ");
				display(Y);
				printf("\n");
				
				system("pause");
				system("cls");
				break;
			case 6:
				printf("\nYou have exited.\n");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
	} while(opt != 6);
	
	return 0;
}
