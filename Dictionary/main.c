#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Dictionary.h"

int main(int argc, char *argv[]) {
	
	Dictionary D;
	initDict(&D, MAX);
	
	insertWord(&D, "hu");
	insertWord(&D, "hi");
	insertWord(&D, "hie");
	insertWord(&D, "hey");
	insertWord(&D, "hello");
	insertWord(&D, "ah");
	
	deleteWord(&D, "hi");
	deleteWord(&D, "hey");
	
	printf("Count: %d\n", D.count);
	visualize(D);
	
	return 0;
}
