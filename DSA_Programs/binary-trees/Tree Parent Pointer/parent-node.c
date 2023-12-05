#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* parent;
	struct node* leftChild;
	struct node* rightChild;
} Tree, *TreePtr;

TreePtr newNode(int data)
{
	TreePtr temp = (TreePtr) malloc(sizeof(Tree));
	
	if(temp != NULL) {
		temp->data = data;
		temp->parent = NULL;
		temp->leftChild = NULL;
		temp->rightChild = NULL;
	}
	
	return temp;
}

void initialize(TreePtr* T)
{
	*T = NULL;
}

void insertNewNode(int data, TreePtr* T)
{
	TreePtr* trav;
	
	for(trav = T; *trav != NULL; ) {
		if(data < (*trav)->data) trav = &(*trav)->leftChild;
		else if(data > (*trav)->data) trav = &(*trav)->rightChild;
	}
	
	if(*trav == NULL) {
		TreePtr temp = newNode(data);
		temp->parent = *trav;
		*trav = temp;
	}
}

int main()
{
	TreePtr newTree;
	initialize(&newTree);
	
	return 0;
}
