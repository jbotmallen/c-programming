#include<stdio.h>
#include<stdlib.h>
#include"declaration.h"
#include"functions.c"

int main()
{
    SET A, B;

    //INITIALIZE SETS A & B
    initialize(&A);
    initialize(&B);

    //INSERT VALUES FOR SETS A & B
    insert(&A, 2);
    insert(&A, 7);
    insert(&A, 9);

    insert(&B, 0);
    insert(&B, 2);
    insert(&B, 4);
    insert(&B, 7);
    insert(&B, 9);

    //DELETE VALUES FROM SETS A AND B
    delete(&A);
    delete(&B);
   
    //GETS THE UNION OF BOTH SETS A & B
    SET C;
    C = UNION(A, B);

    //GETS THE DIFFERENCE OF SET A - B
    SET D;
    D = DIFFERENCE(A, B);

    //GETS THE INTERSECTION OF SETS A AND B
    SET E;
    E = INTERSECTION(A, B);

    //DISPLAYS THE SETS
    printf("THIS IS SET A : \n");
    display(A);
    printf("THIS IS SET B : \n");
    display(B);
    printf("THIS IS SET C (UNION): \n");
    display(C);
    printf("THIS IS SET D (A-B): \n");
    display(D);
    printf("THIS IS SET E (INTERSECTION): \n");
    display(E);

    return 0;
}