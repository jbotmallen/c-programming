#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//STRUCTURE DECLARATION
typedef struct {
    int elem[MAX];
    int top;
} Stack;

//MISCELLANEOUS
char line[30] = {"=============="};

//FUNCTION PROTOTYPES
int initialize(Stack* S);
int push(Stack* S, int elem);
int pop(Stack* S);
int isEmpty(Stack S);
int isFull(Stack S);
int makeNull(Stack* S);
int populateList(Stack* S);
int insertBottom(Stack* S, int elem);
void display(Stack S);


//FUNCTION DEFINITIONS
int initialize(Stack* S)
{
    int retval = 0;

    S->top = 0;

    return retval = 1;
}

int push(Stack* S, int elem)
{
    int retval = 0;

    if(!isFull(*S)) {
        S->elem[S->top++] = elem;
        retval = 1;
    }

    return retval;
}

int pop(Stack* S)
{
    int retval = 0;

    if(!isEmpty(*S)) {
        S->top--;
        retval = 1;
    }

    return retval;
}

int isEmpty(Stack S)
{
    return(S.top == 0);
}

int isFull(Stack S)
{
    return(S.top == MAX);
}

int makeNull(Stack* S)
{
    return (S->top = -1);
}

int populateList(Stack* S)
{
    int x, retval = 0;

    for(x = 0; x < MAX-1; x++) {
        push(S, x + 1);
    }
    S->top = x;

    return retval = 1;
}

int top(Stack S)
{
    if(!isEmpty(S)) return S.elem[S.top-1];
}

int insertBottom(Stack* S, int elem)
{
    int retval = 0;

    if(!isFull(*S)) {
        Stack temp;

        initialize(&temp);
        for(; !isEmpty(*S);) {
            push(&temp, S->elem[S->top-1]);
            pop(S);
        }
        push(S, elem);
        for(; !isEmpty(temp);) {
            push(S, temp.elem[temp.top-1]);
            pop(&temp);
        }

        retval = 1;
    }
    return retval;
}   

void display(Stack S)
{
    if(!isEmpty(S)) {
        Stack temp;

        printf("THE ELEMENTS OF THE LIST : \n%10s%10s\n| %10s | %10s  |\n%10s%10s\n", line, line, "ELEM", "POSITION", line, line);
        for(initialize(&temp); !isEmpty(S); ) {
            printf("| %10d | %10d  |\n%10s%10s\n", S.elem[S.top-1], S.top-1, line, line);
            push(&temp, S.elem[S.top-1]);
            pop(&S);
        }
    } else printf("\n\nSTACK IS EMPTY! PLEASE POPULATE IT FIRST.\n\n");
}

//MISCELLANEOUS OPERATIONS (UNNEEDED & UNWANTED(luuy luuy man))
void pauseAndClear()
{
    system("pause");
    system("cls");
}

#endif