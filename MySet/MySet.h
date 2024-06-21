#ifndef MY_SET
#define MY_SET

#define Data int
#define MAX 5
typedef char String[30];

typedef struct {
	Data set[MAX]; 
	Data count;
}DATA;

void init(DATA *S);
void addVal(DATA *S, Data elem);
void delVal(DATA *S, Data elem);
void findUnion(DATA X, DATA Y);
void findIntersection(DATA X, DATA Y);
void display(DATA S);

#endif
