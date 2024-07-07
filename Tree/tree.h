#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef char String[20];

typedef struct {
	int day, month, year;
} Date;

typedef struct {
	String prodName;
	float prodPrice;
	int prodQty;
	Date expDate;
} Product;

typedef struct node {
	Product item;
	struct node *left, *right;
} Node, *NodePtr;

void init(NodePtr *T);
bool isEmpty(NodePtr T);
NodePtr addProd(NodePtr T, Product P);
NodePtr delProd(NodePtr T, String name);
void travBFS(NodePtr T);
void travInOrder(NodePtr T);
void travPreOrder(NodePtr T);
void travPostOrder(NodePtr T);

#endif
