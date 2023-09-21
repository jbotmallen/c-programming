#include<stdio.h>
#include<stdlib.h>
#include"declaration.h"

void initialize(SET* X)
{
    *X = NULL;
}

void insert(SET* X, int elem) {
    SET temp = (SET)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->num = elem;
        temp->next = NULL;

        SET *ptr;
        for (ptr = X; *ptr != NULL; ptr = &(*ptr)->next) {}
        *ptr = temp;
    }
}

void delete(SET* X)
{
    if(*X != NULL) {
        SET* trav;

        for(trav = X; (*trav)->next != NULL; trav = &(*trav)->next) {}

        SET temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

SET UNION(SET X, SET Y)
{
    SET Z;
    SET xPtr, yPtr, *zPtr;

    initialize(&Z);

    for(xPtr = X, yPtr = Y, zPtr = &Z; xPtr != NULL || yPtr != NULL;) {
        SET temp = (SET) malloc(sizeof(struct node));
        if(temp != NULL) {
            if(xPtr != NULL && (yPtr == NULL || xPtr->num < yPtr->num)) {
                temp->num = xPtr->num;
                xPtr = xPtr->next;
            } else if(yPtr != NULL && (xPtr == NULL || yPtr->num < xPtr->num)) {
                temp->num = yPtr->num;
                yPtr = yPtr->next;
            } else {
                temp->num = xPtr->num;
                xPtr = xPtr->next;
                yPtr = yPtr->next;  
            }
        }
            temp->next = NULL;
            *zPtr = temp;
            zPtr = &(*zPtr)->next;
    }

    return Z;
}

SET DIFFERENCE(SET X, SET Y)
{
    SET Z;
    SET xPtr, yPtr, *zPtr;

    initialize(&Z);
    for(xPtr = X, yPtr = Y, zPtr = &Z; xPtr != NULL; xPtr = xPtr->next) {
        for(; yPtr != NULL && yPtr->num < xPtr->num; yPtr = yPtr->next) {}

        if(yPtr != NULL) {
            SET temp = (SET) malloc(sizeof(struct node));
            if(temp != NULL) {
                temp->num = xPtr->num;
                temp->next = NULL;
                
                *zPtr = temp;
                zPtr = &(*zPtr)->next;
            }
        }
    }

    return Z;
}

SET INTERSECTION(SET X, SET Y)
{
    SET Z;
    SET xPtr, yPtr, *zPtr;

    initialize(&Z);
    for(xPtr = X, yPtr = Y, zPtr = &Z; xPtr != NULL; xPtr = xPtr->next) {
        for(; yPtr != NULL && yPtr->num != xPtr->num; yPtr = yPtr->next) {}

        SET temp = (SET) malloc(sizeof(struct node));
        if(temp != NULL) {
            temp->num = xPtr->num;
            temp->next = NULL;

            *zPtr = temp;
            zPtr = &(*zPtr)->next;
        }
    }

    return Z;
}

void display(SET X)
{
    SET trav;

    for(trav = X; trav != NULL; trav = trav->next)
    printf("| %d ", trav->num);

    printf("|\n");
}