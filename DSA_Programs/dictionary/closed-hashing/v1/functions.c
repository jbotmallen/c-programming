#include "declaration.h"

int hash(int n) {
    return n % PRIMARY_MAX;
}

void init(DICTIONARY* D) {
    int x;

    for (x = 0; x < MAX; x++) {
        D->d[x] = EMPTY;
    }

    D->last = PRIMARY_MAX - 1;
}

int member(DICTIONARY D, int elem) {
    int primaryIdx = hash(elem);
    int x = primaryIdx;

    do {
        if (D.d[x] == elem) {
            return x;
        }
        x = (x + 1) % MAX;
    } while (x != primaryIdx && D.d[x] != EMPTY);

    return -1;
}

void insert(DICTIONARY* D, int elem) {
    int primaryIdx = hash(elem);
    int x = primaryIdx;

    if(D->d[x] != EMPTY && D->d[x] != DELETED && D->d[x] != elem) {
        for(x = PRIMARY_MAX; D->d[x] != EMPTY && D->d[x] != DELETED && D->d[x] != elem; x = (x + 1) % MAX) {}
        if(D->d[x] == EMPTY || D->d[x] == DELETED) {
            D->d[x] = elem;
            D->last = x;
        }
    } else {
        D->d[primaryIdx] = elem;
    }
}

void deleteMem(DICTIONARY* D, int elem)
{
    int primaryIdx = hash(elem);
    int x = primaryIdx;

    if(D->d[x] != elem) {
        for(x = D->last; x < PRIMARY_MAX-1 && D->d[x]; x--) {}
        if(D->d[x] == elem) {
            D->d[x] = DELETED;
        }
    } else {
        D->d[primaryIdx] = DELETED;
    }
}

void display(DICTIONARY D) {
    int x;

    printf("CONTENTS OF THE DICTIONARY\n");
    for (x = 0; x < MAX; x++) {
        printf("ELEMENT AT %02d : %5d\n", x, D.d[x]);
    }
}
