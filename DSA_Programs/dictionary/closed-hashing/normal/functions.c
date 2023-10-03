#include "declarations.h"

int hash(int num)
{
    return num % MAX;
}

void init(DICTIONARY D)
{
    int x;

    for(x = 0; x < MAX; x++) {
        D[x] = EMPTY;
    }
}

int isFull(DICTIONARY D)
{
    int x;

    for(x = 0; x < MAX && D[x] != EMPTY && D[x] != DELETED; x = (x + 1) % MAX) {}
    int retVal = (x < MAX) ? 0 : 1;

    return retVal;
}

void populate(DICTIONARY D)
{
    int x, A[10] = { 15, 67, 27, 35, 97, 43, 4, 88, 88, 5};

    for(x = 0; x < 10; x++) {
        insert(D, A[x]);
    }
}

void insert(DICTIONARY D, int elem)
{
    if(!isFull(D)) {
        int x;

        for(x = hash(elem); D[x] != EMPTY && D[x] != DELETED && D[x] != elem; x = (x + 1) % MAX) {}
        
        if(D[x] == EMPTY || D[x] == DELETED) D[x] = elem;
    }
}

void deleteElem(DICTIONARY D, int elem)
{
    int x;

    for(x = hash(elem); D[x] != EMPTY && D[x] != elem; x = (x + 1) % MAX) {}

    if(D[x] == elem) D[x] = DELETED;
}

void display(DICTIONARY D)
{
    int x;

    for(x = 0; x < MAX; x++) {
        printf("ROW NO %2d : ", x + 1);
        if(D[x] > 0) 
            printf("%d\n", D[x]);
        else if(D[x] == EMPTY)
            printf("EMPTY!\n");
        else
            printf("DELETED!\n");
    }

    system("pause");
    system("cls");
}

int member(DICTIONARY D, int elem)
{
    int x;

    for(x = hash(elem); D[x] != EMPTY && D[x] != elem; x = (x + 1) % MAX) {}

    if(D[x] == EMPTY) x = EMPTY;
    else if(D[x] == DELETED) x = DELETED;

    return x;
}
