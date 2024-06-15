#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int top;
} stackAL;

void initStack(stackAL *s);
stackAL createStack();

bool push(stackAL *s, int elem);
bool pop(stackAL*s);
int peek(stackAL s);

void display(stackAL s);
void visualize(stackAL s);
void evenNumbers(stackAL *s);

#endif
