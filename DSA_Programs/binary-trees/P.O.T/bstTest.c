#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
} BTree, *BTreePtr;

typedef enum {
    TRUE, FALSE
} boolean;

void initialize(BTreePtr* T)
{
    *T = NULL;
}

void insert(BTreePtr* T, int data)
{
    BTreePtr *trav;
    
    for(trav = T; *trav != NULL && (*trav)->data != data;) {
        if((*trav)->data > data) {
            trav = &(*trav)->leftChild;
        }
        else if((*trav)->data < data) {
            trav = &(*trav)->rightChild;
        }
    }
    if(*trav == NULL || (*trav)->data != data) {
        BTreePtr temp = (BTreePtr) malloc(sizeof(BTree));
        
        if(temp != NULL) {
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
            
            *trav = temp;
        }
    }    
}

void display(BTreePtr T)
{
    if (T != NULL) {
        display(T->leftChild);

//        (T->leftChild != NULL) ?
//            printf("LEFT CHILD: %d | ", T->leftChild->data)
//            : printf("NO LEFT CHILD! | ");
//        (T->rightChild != NULL) ?
//            printf("RIGHT CHILD: %d\n", T->rightChild->data)
//            : printf("NO RIGHT CHILD\n");
        printf("PARENT: %d\n", T->data);
        display(T->rightChild);
    }
}


boolean isMember(BTreePtr T, int data)
{
	BTreePtr trav;
	
	for(trav = T; T != NULL && trav->data != data;) {
		if(trav->data < data) trav = trav->rightChild;
		else if(trav->data > data) trav = trav->leftChild;
	}
	
	return(trav != NULL) ? TRUE : FALSE;
}

int main()
{
    BTreePtr tree;
    initialize(&tree);
    
    insert(&tree, 20);
    insert(&tree, 78);
    insert(&tree, 66);
    insert(&tree, 100);
    insert(&tree, 14);
    insert(&tree, 11);
    
    isMember(tree, 11) == TRUE ? printf("Data is in the binary tree\n") : printf("Data is not found in the binary tree\n");
    system("pause");
    system("cls");
    display(tree);
    
    return 0;
}
