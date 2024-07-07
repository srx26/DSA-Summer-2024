#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Dictionary.h"

void initDict(Dictionary *d, int size) {
	
	int i;
	d->count = 0;
	d->max = MAX;
	for(i=0; i<d->max; i++) {
		d->wordList[i] = NULL;
	}
}

int hash(char x) {
	
	return x - 31;
}

void insertWord(Dictionary *d, String w) {
	
	Word *temp = malloc(sizeof(Word));
	int index = hash(w[0]) % d->max;
	
	strcpy(temp->word, w);
	temp->next = NULL;
	
	if(d->wordList[index] == NULL) {
		d->wordList[index] = temp;
		d->count += 1;
	}
	else {
		if(strcmp(d->wordList[index]->word, w) > 0) {
			temp->next = d->wordList[index];
			d->wordList[index] = temp;
		}
		else {
			Word **trav = &(d->wordList[index]);
		
			for(; *trav != NULL && strcmp(temp->word, (*trav)->word) < 0; trav = &(*trav)->next) { }
			
			if(*trav == NULL) {
				*trav = temp;
			}
			else {
				temp->next = *trav;
				*trav = temp;
			}
		}
		d->count += 1;
	}
}

void deleteWord(Dictionary *d, String w) {
	
	int index = hash(w[0]) % d->max;
	Word *temp = malloc(sizeof(Word));
	Word **trav = &(d->wordList[index]);
	
	for(; *trav != NULL; trav = &(*trav)->next) {
		
		if(strcmp(w, (*trav)->word) == 0) {
			temp = *trav;
			temp->next = (*trav)->next;
			*trav = temp->next;
			d->count -= 1;
			free(temp);
			break;
		}
	}
}

Dictionary resize(Dictionary *d) {
	
}

void visualize(Dictionary d) {
	
	Dictionary *trav = &d;
	int i;
	
	for(i=0; i<MAX; i++) {
		printf("%d - ", i);
		
		while(trav->wordList[i] != NULL) {
			printf("%s", trav->wordList[i]->word);
			if(trav->wordList[i]->next != NULL) {
				printf(", ");
			}
			trav->wordList[i] = trav->wordList[i]->next;
		}
		
		printf("\n");
	}
}
