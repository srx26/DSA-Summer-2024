#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main() {
	
	NodePtr tree;
	Product newProd;
	int opt, i;
	String pName, menu[20] = {"Add Product", "Delete Product", "Display", "Exit"};
	
	init(&tree);
	
	do {
		printf("MENU\n");
		for(i=0; i<4; i++) {
			printf("%d. %s\n", i+1, menu[i]);
		}
		printf("Choose an option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				system("cls");
				printf("ADD PRODUCT\n\n");
				
				printf("Product Name: ");
				scanf("%s", &newProd.prodName);
				printf("Product Price: ");
				scanf("%f", &newProd.prodPrice);
				printf("Product Quantity: ");
				scanf("%d", &newProd.prodQty);
				printf("Product ExpDate (mm-dd-yyyy): ");
				scanf("%d %d %d", &newProd.expDate.month, &newProd.expDate.day, &newProd.expDate.year);
				
				tree = addProd(tree, newProd);
				
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("DELETE PRODUCT\n\n");
				
				if(!isEmpty(tree)) {
					printf("Enter Product Name: ");
					scanf("%s", &pName);
					
					delProd(tree, pName);
				}
				else {
					printf("The Tree is empty.\n");
				}
				
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf("DISPLAY\n\n");
				
				int travOpt;
				String travMenu[20] = {"BFS", "In Order", "Pre Order", "Post Order", "Go Back"};
				
				if(!isEmpty(tree)) {
					do {
						for(i=0; i<5; i++) {
							printf("%d. %s\n", i+1, travMenu[i]);
						}
						printf("Choose an option: ");
						scanf("%d", &travOpt);
						
						switch(travOpt) {
							case 1:
								system("cls");
								printf("BFS\n\n");
//								travBFS(tree);
								
								system("pause");
								system("cls");
								break;
							case 2:
								system("cls");
								printf("In Order\n\n");
								travInOrder(tree);
								
								system("pause");
								system("cls");
								break;
							case 3:
								system("cls");
								printf("Pre Order\n\n");
								travPreOrder(tree);
								
								system("pause");
								system("cls");
								break;
							case 4:
								system("cls");
								printf("Post Order\n\n");
								travPostOrder(tree);
								
								system("pause");
								system("cls");
								break;
							case 5:	
								break;
							default:
								system("cls");
								break;	
						}
						
					} while(travOpt != 5);
				}
				else {
					printf("The Tree is empty.\n");
					system("pause");
				}
				system("cls");
				break;
			case 4:
				printf("\nYou have exited.\n");
				break;
			default:
				system("pause");
				system("cls");
				break;
		}
		
	} while(opt != 4);
	
//	strcpy(newProd.prodName, "Pares");
//	newProd.prodPrice = 50.00;
//	newProd.prodQty = 20;
//	newProd.expDate.day = 1;
//	newProd.expDate.month = 2;
//	newProd.expDate.year = 2024;
	
//	tree = addProd(tree, newProd);
//	printf("Product Name: %s\nProduct Price: %.2f\nProduct Quantity: %d\nExpiry Date (mm-dd-yyyy): %d-%d-%d\n", tree->item.prodName, tree->item.prodPrice, tree->item.prodQty, tree->item.expDate.month, tree->item.expDate.day, tree->item.expDate.year);
	
	return 0;
}
