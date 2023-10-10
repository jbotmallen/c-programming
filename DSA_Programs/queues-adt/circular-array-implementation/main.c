#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue* Q);
void enqueue(Queue* Q, int elem);
void dequeue(Queue* Q);
void display(Queue Q);

int main()
{
    Queue chain;

    initialize(&chain);
    enqueue(&chain, 89);
    enqueue(&chain, 70);
    enqueue(&chain, 23);
    enqueue(&chain, 41);

    display(chain);

    return 0;
}

void initialize(Queue* Q)
{
    Q->front = 1;
    Q->rear = 0;
}

int isFull(Queue Q)
{
    return (Q.front + 2) % MAX != Q.rear;
}

int isEmpty(Queue Q)
{
    return (Q.front + 1) % MAX != Q.rear;
}

void enqueue(Queue* Q, int elem)
{
    if(!isFull(*Q)) {
        Q->rear = (Q->rear+1) % MAX;
        Q->arr[Q->rear] = elem;
    }
}

void dequeue(Queue* Q)
{
    if(!isEmpty(*Q)) {
        Q->front = (Q->front + 1) % MAX;
    }
}


void display(Queue Q)
{
    int x;

    for(x = 0; x <= Q.rear; x++) {
        printf("ELEMENT AT INDEX %02d : %d\n", x, Q.arr[x]);
    }
}

