#include"header2.h"

void initialize(POTPtr P)
{
	P->last = -1;
}

void populate(POTPtr P, int arr[])
{
	int i;
	
	for(i = 0; i < MAX; i++) {
		P->elem[++P->last] = arr[i];
	}
}

void swap(int* parent, int* child)
{
	int temp = *parent;
	*parent = *child;
	*child = temp;
}

void heapify(POTPtr P)
{
	
	int parent, rc, lc, sc;
	
	for(parent = (P->last-1)/2; parent >= 0; parent--) {
		lc = (2*parent) + 1;
		rc = lc + 1;
		sc = (rc < P->last) ?
			(P->elem[rc] > P->elem[lc]) ? lc : rc
		: lc;
		
		if(P->elem[sc] < P->elem[parent]) swap(&P->elem[parent], &P->elem[sc]);
	}
}

void display(POT P)
{
	int i;
	
	for(i = 0; i <= P.last; i++) {
		printf("%d | ", P.elem[i]);
	}
	
	printf("\n");
}
