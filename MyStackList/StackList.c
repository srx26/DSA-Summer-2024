#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackList.h"

void initStack(NodePtr *head) {
	*head = NULL;
}

bool isEmpty(NodePtr head) {
	return (head == NULL);
}

void push(NodePtr *head, int elem) {
	
	NodePtr nD = malloc(sizeof(Node));
	
	if(isEmpty(*head)) {
		nD->data = elem;
		nD->next = NULL;
		*head = nD;
	}
	else {
		nD->data = elem;
		nD->next = *head;
		*head = nD;
	}
}

void pop(NodePtr *head) {
	
	NodePtr temp;
	
	if(isEmpty(*head)) {
		printf("\nThe Stack is Empty.\n");
	}
	else {
		temp = *head;
		printf("\nElement %d has been popped!\n\n", temp->data);
		*head = (*head)->next;
		free(temp);
	}
}

int peek(NodePtr head) {
	
	NodePtr curr = head;
	
	if(isEmpty(head)) {
		printf("\nThe Stack is Empty.\n");
		return 0;
	}
	else {
		return curr->data;
	}
}

void display(NodePtr head) {
	
	NodePtr temp = head;
	NodePtr newStack;
	initStack(&newStack);
	
	while(!isEmpty(temp)) {
		int top = peek(temp);
		push(&newStack, top);
		pop(&temp);
	}
	
	printf("New Stack: ");
	while(!isEmpty(newStack)) {
		int top = peek(newStack);
		printf("%d ", top);
		pop(&newStack);
	}
	printf("\n");
}

void visualize(NodePtr head) {
	
	NodePtr current = head;
	
	printf("LIST: \n");
	while(current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

