#ifndef DECLARATION_H
#define DECLARATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define PRIMARY_MAX 10
#define EMPTY -1
#define DELETED -2

typedef int LIST[MAX];
typedef struct {
    LIST d;
    int last;
} DICTIONARY;

int hash(int n);
void init(DICTIONARY* D);
int member(DICTIONARY D, int elem);
void insert(DICTIONARY* D, int elem);
void deleteMem(DICTIONARY* D, int elem);

#endif