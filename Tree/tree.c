#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void init(NodePtr *T) {
	*T = NULL;
}

bool isEmpty(NodePtr T) {
	return (T == NULL);
}

NodePtr addProd(NodePtr T, Product P) {
	
	NodePtr nP = malloc(sizeof(Node));
	
	if(isEmpty(T)) {
		
		nP->item = P;
		nP->left = NULL;
		nP->right = NULL;
		
		return nP;
	}
	if(strcmp(T->item.prodName, P.prodName) > 0) {
		T->left = addProd(T->left, P);
	}
	else if(strcmp(T->item.prodName, P.prodName) < 0) {
		T->right = addProd(T->right, P);
	}
	return T;
}

NodePtr delProd(NodePtr T, String name) {
	
	NodePtr temp;
	
	if(isEmpty(T)) {
		printf("\nProduct does not exist.\n");
		return;
	}
	else if(strcmp(T->item.prodName, name) > 0) {
		T->left = delProd(T->left, name);
	}
	else if(strcmp(T->item.prodName, name) < 0) {
		T->right = delProd(T->right, name);
	}
	else {
		if(isEmpty(T->left)) {
			temp = T->right;
			
			free(T);
			return temp;
		}
		else if(isEmpty(T->right)) {
			temp = T->left;
			
			free(T);
			return temp;
		}	
	}
	
	return T;
}

void travBFS(NodePtr T) {
	
	if(!isEmpty(T)) {
		printf("%s\n", T->item.prodName);
		travBFS(T->left);
		travBFS(T->right);
	}
}

//LNR
void travInOrder(NodePtr T) {
	
	if(!isEmpty(T)){
		travInOrder(T->left);
		printf("%s\n", T->item.prodName);
		travInOrder(T->right);
	}
}

//NLR
void travPreOrder(NodePtr T) {
	
	
	if(!isEmpty(T)){
		printf("%s\n", T->item.prodName);
		travPreOrder(T->left);
		travPreOrder(T->right);
	}
}

//LRN
void travPostOrder(NodePtr T) {
	
	if(!isEmpty(T)){
		travPostOrder(T->left);
		travPostOrder(T->right);
		printf("%s\n", T->item.prodName);
	}
}
