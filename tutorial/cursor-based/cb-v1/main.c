#include<stdio.h>
#define MAX 5

typedef int CLIST;

typedef struct { 
    int num;
    int next;
} Nodes;

typedef struct {
    Nodes elements[MAX];
    int avail;
} CURSOR;


//hello i am jethro