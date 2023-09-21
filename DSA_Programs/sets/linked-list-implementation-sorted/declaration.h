#ifndef DECLARATION_H
#define DECLARATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int num;
    struct node* next;
} *SET;

void initialize(SET* X);
void insert(SET* X, int elem);
void delete(SET* X);
SET UNION(SET X, SET Y);
SET DIFFERENCE(SET X, SET Y);
SET INTERSECTION(SET X, SET Y);
void display(SET X);

#endif