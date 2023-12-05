#include "header.h"

void initialize(HeapPtr H)
{
	H->lastIdx = -1;
}

void populate(HeapPtr H)
{
	int arr[MAX] = {
		7, 5, 4, 3, 6, 2, 1, 8, 1
	};
	int i;
	
	for(i = 0; i < MAX; i++) {
		insert(H, arr[i]);
	}
}

void insert(HeapPtr H, int value)
{
	H->elem[++H->lastIdx] = value;
	
	if(H->lastIdx != 0) {
		int child, parent;
		
		for(child = H->lastIdx, parent = (child - 1)/2; child != 0 && H->elem[child] <= H->elem[parent]; child = parent, parent = (child - 1)/2) {
			swap(&H->elem[child], &H->elem[parent]);
		}
	}
}

void swap(int* child, int* parent)
{
	int temp = *child;
	*child = *parent;
	*parent = temp;
}

void deleteMin(HeapPtr H)
{
	if(H->lastIdx != -1) {
		int RMChild = H->lastIdx--, root = 0;
		int SMChild, lChild = (2*root)+1, rChild = lChild+1;
		
		swap(&H->elem[RMChild], &H->elem[root]);
		SMChild = (H->elem[lChild] < H->elem[rChild]) ? lChild : rChild;
		 
		for(lChild = (2*root)+1, rChild = lChild+1; SMChild <= H->lastIdx && H->elem[root] > H->elem[SMChild];
		root = SMChild, lChild = (2*root)+1, rChild = lChild+1, SMChild = (H->elem[lChild] < H->elem[rChild]) ? lChild : rChild) {
			swap(&H->elem[SMChild], &H->elem[root]);		
		}
	}
}

void display(Heap H)
{
	int i;
	
	printf("THE PARTIALLY ORDERED TREE IS: ");
	for(i = 0; i <= H.lastIdx; i++) {
		printf("| %d ", H.elem[i]);
	}
	printf("\n\n");
}
