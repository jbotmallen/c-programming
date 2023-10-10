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

int main()
{
    Queue chain;

    initialize(&chain);
    enqueue(&chain, 89);
    enqueue(&chain, 70);
    enqueue(&chain, 23);
    enqueue(&chain, 41);

    return 0;
}

void initialize(Queue* Q)
{
    Q->front = -1;
    Q->rear = -1;
}

void enqueue(Queue* Q, int elem)
{
    if((Q->rear + 1) % MAX != Q->front) {
        Q->arr[++Q->rear] = elem;
        if((Q->front+1) % MAX == Q->rear) {
            Q->front++;
        }
    }
}

void dequeue(Queue* Q)
{
    if(Q->front != Q->rear) {
        Q->front++;
    }
}


