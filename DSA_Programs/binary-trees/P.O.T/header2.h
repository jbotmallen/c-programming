#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
	int elem[MAX];
	int last;
} POT, *POTPtr;

void initialize(POTPtr P);
void populate(POTPtr P, int arr[]);
void heapify(POTPtr P);
void display(POT P);
