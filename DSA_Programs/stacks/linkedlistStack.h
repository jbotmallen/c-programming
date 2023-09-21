#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node{
    int elem;
    struct node* link;
} *Stack;

//MISCELLANEOUS
char line[30] = {"=============="};

int initialize(Stack* S);
int push(Stack* S, int elem);
int pop(Stack* S);
int isEmpty(Stack S);
int isFull(Stack S);
int makeNull(Stack* S);
int populateList(Stack* S);
int insertBottom(Stack* S, int elem);
void display(Stack S);

int initialize(Stack* S)
{
    int retval = 0;
    
    *S = NULL;

    return retval = 1;
}

int push(Stack* S, int elem)
{
    Stack temp = (Stack) malloc(sizeof(struct node));
    int retval = 0;

    temp->elem = elem;
    temp->link = *S;

    *S = temp;

    return retval = 1;
}

int pop(Stack* S)
{
    int retval = 0;

    if(!isEmpty(*S)) {
        Stack temp;

        temp = *S;
        *S = temp->link;

        free(temp);
        retval = 1;
    }

    return retval;
}

int isEmpty(Stack S)
{
    return (S == NULL);
}

int isFull(Stack S)
{
    return 0;
}

int makeNull(Stack* S)
{
    int retval = 0;

    if(*S != NULL) {
        Stack temp;

        temp = *S;
        *S = temp->link;

        free(temp);

        makeNull(S);

        retval = 1;
    }

    return retval;
}

int populateList(Stack* S) {
    int x, retval = 0;
    
    for(x = 0; x < MAX-1; x++) {
        push(S, x + 1);
    }

    return retval = 1;
}

int insertBottom(Stack* S, int elem)
{
    Stack temp;
    int retval;

    initialize(&temp);
    for(; !isEmpty(*S);) {
        push(&temp, (*S)->elem);
        pop(S);
    }
    push(S, elem);
    printf("\n\n");
    for(; !isEmpty(temp);) {
        push(S, temp->elem);
        pop(&temp);
    }

    return retval = 1;
}

int top(Stack S)
{
    if(!isEmpty(S)) return S->elem;
}

void display(Stack S)
{
    if(!isEmpty(S)) {
        Stack temp;
        printf("THE ELEMENTS OF THE LIST : \n%10s\n| %10s |\n%10s\n", line, "ELEM", line);
        
        for(initialize(&temp); !isEmpty(S); ) {
            printf("| %10d |\n%10s\n", S->elem, line);
            push(&temp, S->elem);
            pop(&S);
        }

        for(; !isEmpty(temp); ) {
            push(&S, temp->elem);
            pop(&temp);
        }
    } else printf("\n\nLIST IS EMPTY! POPULATE THE LIST FIRST.\n\n");
}

//MISCELLANEOUS FUNCTIONS
void pauseAndClear()
{
    system("pause");
    system("cls");
}

#endif