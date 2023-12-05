#include <stdio.h>
#include <stdlib.h>

//DEFINE MAX VALUES
#define MAX 10

//Structure Data Types
typedef struct node {
	int data;
	struct node* parent;
	struct node* leftChild;
	struct node* rightChild;
} Node, *NodePtr;

//Functions
void initialize(NodePtr T);
