#include<stdio.h>
#include<stdlib.h>

//DEFINITIONS
typedef struct celltype{
    int elem;
    struct celltype* next;
} record;

typedef struct {
    record* front;
    record* rear;
} QUEUE;

//PROTOTYPES
void initialize(QUEUE* Q);
void makeNull(QUEUE* Q);
void enqueue(QUEUE* Q, int elem);
void dequeue(QUEUE* Q);

int main()
{
    QUEUE chain;

    //INITIALIZATION
    initialize(&chain);

    //ENQUEUE OPERATIONS
    enqueue(&chain, 10);
    enqueue(&chain, 20);
    enqueue(&chain, 30);

    //DEQUEUE OPERATIONS
    dequeue(&chain);

    return 0;
}

void initialize(QUEUE* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}

void makeNull(QUEUE* Q)
{
    for(; Q->front != NULL; ) {
        record* temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    Q->rear = NULL;
}

void enqueue(QUEUE* Q, int elem)
{
    record* newEntry = (record*) malloc(sizeof(record));
    newEntry->elem = elem;
    newEntry->next = NULL;

    if(Q->rear == NULL) {
        Q->front = newEntry;
        Q->rear = newEntry;
    } else {
        Q->rear->next = newEntry;
        Q->rear = newEntry;
    }
}

void dequeue(QUEUE* Q)
{
    if(Q->front != NULL) {
        record* temp = Q->front;

        if(Q->front == Q->rear) {
            Q->front = NULL;
            Q->rear = NULL;
        } else {
            Q->front = Q->front->next;
        }
        free(temp);
    }
}