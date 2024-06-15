#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	stackAL list;
	
	initStack(&list);
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	push(&list, 4);
	push(&list, 5);
	
	peek(list);
	
	display(list);
	
	printf("\nPopped: ");
	pop(&list);
	printf("\n");
	peek(list);
	
	visualize(list);
	
	evenNumbers(&list);
	
	visualize(list);
	
	return 0;
}
