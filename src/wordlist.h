#ifndef WORDLIST_H
#define WORDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef struct tnode* Address;
typedef struct tnode {
    char word[20];
    int length;
    Address next;
} Node;
typedef Address wordList;
#define word(L) (L)->word
#define next(L) (L)->next
#define first(L) (L)
#define length(L) (L)->length

Address newNode (char w[20]);
void enqueue (wordList *wl, char w[20]);
void dequeue (wordList *wl);
void print_wordList (wordList w);

#endif