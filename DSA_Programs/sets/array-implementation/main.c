#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef int SET[MAX];

void Member(SET X);
void Insert(SET X, int idx);
void Delete(SET X, int idx);
SET* UNION(SET X, SET Y);
SET* INTERSECTION(SET X, SET Y);
SET* DIFFERENCE(SET X, SET Y);
void Display(SET X);

int main()
{
    SET A, B;

    //INITIALIZE SETS
    Member(A);
    Member(B);

    //INSERT AT INDEX
    Insert(A, 7);
    Insert(A, 0);
    Insert(A, 2);
    Insert(A, 4);

    Insert(B, 7);
    Insert(B, 6);
    Insert(B, 2);

    //UNION OF SETS A & B
    SET* C;
    C = UNION(A, B);
    //INTERSECTION OF SETS A & B
    SET* D;
    D = INTERSECTION(A, B);
    //DIFFERENCE BETWEEN SETS A - B
    SET* E;
    E = DIFFERENCE(B, A);

    //DISPLAY ALL SETS
    printf("SET A:\n=========================================\n");
    Display(A);
    printf("SET B:\n=========================================\n");
    Display(B);
    printf("SET C (UNION):\n=========================================\n");
    Display(*C);
    printf("SET D (INTERSECTION):\n=========================================\n");
    Display(*D);
    printf("SET E (DIFFERENCE):\n=========================================\n");
    Display(*E);

    return 0;
}

//OPERATIONS (Member, Insert, Delete)
void Member(SET X)
{
    int p;

    for(p = 0; p < MAX; p++)
        X[p] = 0;
}

void Insert(SET X, int idx)
{
    if(idx < MAX)
        X[idx] = 1;
}

void Delete(SET X, int idx)
{
    if(idx < MAX)
        X[idx] = 0;
}

//OPERATIONS (UNION, INTERSECTION, DIFFERENCE)
SET* UNION(SET X, SET Y)
{
    int p;
    SET* Z = (SET*) malloc(sizeof(SET));

    for(p = 0; p < MAX; p++) {
        (*Z)[p] = X[p] || Y[p];
    }

    return Z;
}

SET* INTERSECTION(SET X, SET Y)
{
    int p;
    SET* Z = (SET*) malloc(sizeof(SET));

    for (p = 0; p < MAX; p++) {
        (*Z)[p] = X[p] && Y[p];
    }

    return Z;    
}

SET* DIFFERENCE(SET X, SET Y)
{
    int p;
    SET* Z = (SET*) malloc(sizeof(SET));

    for(p = 0; p < MAX; p++) {
        (*Z)[p] = X[p] && !Y[p];
    }

    return Z;
}

//FOR DISPLAY
void Display(SET X)
{
    int p;

    for(p = 0; p < MAX; p++) {
        printf("| %d ", X[p]);
    }
    printf("|\n=========================================\n\n");
}

