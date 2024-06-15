#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(stackAL *s) {
	s->top = -1;
}

stackAL createStack() {
	
}


bool push(stackAL *s, int elem) {
	
	s->top += 1;
	s->data[s->top] = elem;
}

bool pop(stackAL*s) {
	
	printf("%d \n", s->data[s->top--]);
	
}

int peek(stackAL s) {
	
	printf("Top: %d\n\n", s.top);
	printf("Value at index %d: %d\n\n", s.top, s.data[s.top]);
}


void display(stackAL s) {
	
	printf("DISPLAY:\n");
	
	while(s.top != -1) {
		pop(&s);
	}
}

void visualize(stackAL s) {
	
	int i = 0;
	
	printf("\n%s\t%s\n", "INDEX", "VALUE");
	
	while(i <= s.top) {
		
		if(i == s.top) {
			printf("%d\t%d\t%s\n", i, s.data[i], "TOP");
		}
		else {
			printf("%d\t%d\n", i, s.data[i]);
		}
		
		i += 1;
	}
}


void evenNumbers(stackAL *s) {
	
	printf("\nEven Numbers: \n");
	
	while(s->top != -1) {
		
		if(s->data[s->top] % 2 == 0) {
			pop(s);
		}
		else {
			s->top -= 1;
		}
	}
}
