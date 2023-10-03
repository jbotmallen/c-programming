#ifndef DECLARATION_H
#define DECLARATION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct node {
    int elem;
    struct node* next;
} *LIST, nodeType;

typedef LIST Dictionary[MAX];

void init(Dictionary D);
int hash(int num);
void insert(Dictionary D, int elem);
void deleteElem(Dictionary D, int elem);
int member(Dictionary D, int elem);
void display(Dictionary D);

#endif