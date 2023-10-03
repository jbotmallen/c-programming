#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define EMPTY -1
#define DELETED 0

typedef int DICTIONARY[MAX];

int hash(int num);
void init(DICTIONARY D);
int isFull(DICTIONARY D);
void populate(DICTIONARY D);
void insert(DICTIONARY D, int elem);
void deleteElem(DICTIONARY D, int elem);
void display(DICTIONARY D);

#endif