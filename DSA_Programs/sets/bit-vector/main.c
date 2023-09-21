#include<stdio.h>
#include<stdlib.h>
#include"declaration.h"
#include"functions.c"

int main()
{
    system("cls");
    SET A, B, C, D, E;
    initialize(&A);
    initialize(&B);
    initialize(&C);
    initialize(&D);
    initialize(&E);

    displayBitPattern(A);

    insert(&A, 2);
    insert(&A, 6);
    insert(&A, 4);

    insert(&B, 3);
    insert(&B, 1);
    insert(&B, 2);

    printf("===================================\n");
    printf("THIS IS THE BIT PATTERN OF SET A : ");
    displayBitPattern(A);
    displaySet(A);
    printf("===================================\n");

    printf("===================================\n");
    printf("THIS IS THE BIT PATTERN OF SET B : ");
    displayBitPattern(B);
    displaySet(B);
    printf("===================================\n");

    C = UNION(A, B);
    printf("===================================\n");
    printf("THIS IS THE BIT PATTERN OF SET C : ");
    displayBitPattern(C);
    displaySet(C);
    printf("===================================\n");


    D = INTERSECTION(A, B);
    printf("===================================\n");
    printf("THIS IS THE BIT PATTERN OF SET D : ");
    displayBitPattern(D);
    displaySet(D);
    printf("===================================\n");

    E = DIFFERENCE(A, B);
    printf("===================================\n");
    printf("THIS IS THE BIT PATTERN OF SET E : ");
    displayBitPattern(E);
    displaySet(E);
    printf("===================================\n");

    return 0;
}