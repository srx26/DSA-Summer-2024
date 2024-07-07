#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX 10

typedef char String[30];

typedef struct node {
	String word;
	struct node *next;
} Word;

typedef struct {
	Word *wordList[MAX];
	int count;
	int max;
} Dictionary;

void initDict(Dictionary *d, int size);
int hash(char x);
void insertWord(Dictionary *d, String w);
void deleteWord(Dictionary *d, String w);
Dictionary resize(Dictionary *d);
void visualize(Dictionary d);

#endif
