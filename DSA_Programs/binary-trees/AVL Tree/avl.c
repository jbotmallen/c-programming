#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
} Tree, *TreePtr;

void initialize(TreePtr* T)
{
    *T = NULL;
}

void insertNode(int elem, TreePtr* T)
{
//    TreePtr* trav;
//    
//    for(trav = T; *trav != NULL && (*trav)->data != elem; ) {
//        if(elem < (*trav)->data) trav = &(*trav)->leftChild;
//        else if(elem > (*trav)->data) trav = &(*trav)->rightChild;
//    }
//    
//    if(*trav == NULL) {
//        TreePtr temp = (TreePtr) malloc(sizeof(Tree));
//        
//        if(temp != NULL) {
//            temp->data = elem;
//            temp->leftChild = NULL;
//            temp->rightChild = NULL;
//            
//            *trav = temp;
//        }
//    }

    if(*T != NULL && (*T)->data != elem) {
        if(elem < (*T)->data) insertNode(elem, &(*T)->leftChild);
        else if(elem > (*T)->data) insertNode(elem, &(*T)->rightChild);
    }
    
    if(*T == NULL) {
        TreePtr temp = (TreePtr) malloc(sizeof(Tree));
        
        if(temp != NULL) {
            temp->data = elem;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
            
            *T = temp;
        }
    }
}

TreePtr leftMostChild(TreePtr T)
{
    TreePtr trav;
    
    for(trav = T; trav->leftChild != NULL; trav = trav->leftChild) {}
    
    if(trav->leftChild != NULL) {
        trav = NULL;
    }
    
    return trav;
}

void deleteNode(TreePtr* T, int elem)
{
    if(*T != NULL) {
        TreePtr* trav;
        
        for(trav = T; *trav != NULL && (*trav)->data != elem;) {
            if(elem < (*trav)->data) trav = &(*trav)->leftChild;
            else if(elem > (*trav)->data) trav = &(*trav)->rightChild;
        }
        if(*trav != NULL) {
            TreePtr temp;
            
            if((*trav)->leftChild == NULL && (*trav)->rightChild == NULL) {
                temp = *trav;
                *trav = temp->leftChild;
                free(temp);
            } else if((*trav)->leftChild != NULL && (*trav)->rightChild == NULL) {
                temp = (*trav)->leftChild;
                (*trav)->data = temp->data;
                free(temp);
            } else if((*trav)->rightChild != NULL && (*trav)->leftChild == NULL) {
                temp = (*trav)->rightChild;
                (*trav)->data = temp->data;
                free(temp);
            } else {
                TreePtr *trav2;
                for(trav2 = trav; (*trav2)->leftChild != NULL; trav2 = &(*trav2)->leftChild) {}
                
                if((*trav2)->leftChild == NULL) {
                  temp = *trav2;
                  *trav2 = temp->leftChild;
                  (*trav)->data = temp->data;
                }
                free(temp);
            }
        }
    }
}

void display(TreePtr T)
{
    if(T != NULL) {
	    display(T->leftChild);
	    display(T->rightChild);
	    printf("Parent: %d\n", T->data);
	    T->leftChild != NULL ? printf("Left Child: %2d | ", T->leftChild->data) : printf("No left child | ");
	    T->rightChild != NULL ? printf("Right Child: %2d\n", T->rightChild->data) : printf("No right child\n");
	}
}

void populate(TreePtr* T)
{
    int data[] = {
        12, 8, 18, 5, 11, 17, 4
    }, i;
    
    for(i = 0; i < 7; i++) {
        insertNode(data[i], T);
    }
}

int main()
{
    TreePtr tree;
    initialize(&tree);
    
    populate(&tree);
    
//    TreePtr lmc = leftMostChild(tree);
//    lmc == NULL ? printf("LIST IS EMPTY!\n\n") : printf("LEFTMOST CHILD OF THIS TREE IS : %2d\n\n", lmc->data);
    display(tree);
    system("pause");
    system("cls");
    deleteNode(&tree, 8);
    display(tree);
    
    return 0;
}
