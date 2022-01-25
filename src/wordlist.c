#include "wordlist.h"

Address newNode (char w[20]) {
    int n;
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        n = 0;
        while (n < 20 && w[n] != '\0') {
            word(p)[n] = w[n];
            n++;
        }
        length(p) = n;
        next(p) = NULL;
    }
    return p;
}

void enqueue (wordList *wl, char w[20]) {
    Address pNew, pList;
    pNew = newNode(w);
    if (pNew != NULL) {
        if (first(*wl) == NULL) {
            first(*wl) = pNew;
        }
        else {
            pList = first(*wl);
            while (next(pList) != NULL) {
                pList = next(pList);
            }
            next(pList) = pNew;
        }
    }
}

void dequeue (wordList *wl) {
    Address p;
    p = first(*wl);
    if (next(p) == NULL) {
        first(*wl) = NULL;
    }
    else {
        first(*wl) = next(p);
    }
    free(p);
}

void print_wordList (wordList w) {
    Address p = first(w);
    int i;
    while (p != NULL) {
        for (i = 0; i < length(p); i++) {
            printf("%c", word(p)[i]);
        }
        printf("\n");
        p = next(p);
    }
}