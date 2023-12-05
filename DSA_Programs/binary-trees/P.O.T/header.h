#include<stdio.h>
#include<stdlib.h>

//DEFINE MAX ARRAY SIZE FOR THE HEAP
#define MAX 9

//P.O.T. STRUCT DATA TYPE
typedef struct {
	int elem[MAX];
	int lastIdx;
} Heap, *HeapPtr;

//FUNCTIONS
void initialize(HeapPtr H);
void populate(HeapPtr H);
void insert(HeapPtr H, int value);
void swap(int* child, int* parent);
void display(Heap H);
void deleteMin(HeapPtr H);
