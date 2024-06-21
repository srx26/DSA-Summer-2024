#include <stdio.h>
#include <stdlib.h>
#include "MySet.h"

void init(DATA *S) {
	
	int i;
	
	for(i=0; i<MAX; i++) {
		S->set[i] = -1;
	}
	S->count = 0;
}

void addVal(DATA *S, Data elem) {
	
	if(S->count != MAX) {
		S->set[S->count] = elem;
		S->count += 1;
	}
	else {
		printf("\nArray is Full.\n");
	}
}

void delVal(DATA *S, Data elem) {
	
	int i, check = 0;
	
	for(i=0; i<MAX; i++) {
		if(i == elem) {
			if(S->set[i] == -1) {
				break;
			}
			else {
				S->set[i] = -1;
				S->count -= 1;
				check = 1;
			}
		}
	}
	if(check) {
		printf("\nIndex %d is deleted.\n", elem);
	}
	else {
		printf("\nIndex %d has no value.\n", elem);
	}
}

void findUnion(DATA X, DATA Y) {
	
	int i, j, elem;
	DATA N;
	init(&N);
	
	for(i=0; i<MAX; i++) {
		if(X.set[i] == -1) {
			continue;
		}
		else {
			elem = X.set[i];
			addVal(&N, elem);
		}
	}
	
	for(i=0; i<MAX; i++) {
		if(Y.set[i] == -1) {
			continue;
		}
		for(j=0; j<MAX; j++) {
			if(N.set[j] != Y.set[i]) {
				elem = X.set[i];
				addVal(&N, elem);
			}
		}
	}
	display(N);
	
	printf("\n");
}

void findIntersection(DATA X, DATA Y) {
	
	int i, j;
	
	for(i=0; i<MAX; i++) {
		for(j=0; j<MAX; j++) {
			if(X.set[i] == Y.set[j]) {
				if(X.set[i] == -1) {
					continue;
				}
				else {
					printf("%d ", X.set[i]);
				}
			}
		}
	}
	printf("\n");
}

void display(DATA S) {
	int i;
	
	for(i=0; i<MAX; i++) {
		if(S.set[i] == -1) {
			printf("");
		}
		else {
			printf("%d ", S.set[i]);
		}
	}
	printf("\n");
}

