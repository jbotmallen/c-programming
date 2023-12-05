#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ID 10
#define MAX_REC 15

typedef enum {
	TRUE, FALSE
} Boolean;

typedef struct {
	char FN[24], LN[16], MI;
} nameType;

typedef struct {
	char ID[MAX_ID];
	nameType name;
	char course[8];
	int yrLevel;
} studRec;

typedef struct {
	studRec records[MAX_REC];
	int top;
} Stack, *StackPtr;

typedef struct {
	studRec studs[MAX_REC];
	int front;
	int rear;
} Queue, *QueuePtr;

typedef struct {
	Stack S;
	Queue Q;
} Lists, *ListPtr;

//HELPER FUNCTIONS
nameType newName(char FN[], char LN[], char MI)
{
	nameType name;
	
	strcpy(name.FN, FN);
	strcpy(name.LN, LN);
	name.MI = MI;
	
	return name;
}

studRec newStudent(char ID[], nameType name, char course[], int yrLevel)
{
	studRec stud;
	
	strcpy(stud.ID, ID);
	stud.name = name;
	strcpy(stud.course, course);
	stud.yrLevel = yrLevel;
	
	return stud;
}

//STACK FUNCTIONS
void initializeStack(StackPtr S)
{
	S->top = 0;
}

void push(StackPtr S, studRec stud)
{
	if(S->top != MAX_REC) {
		S->records[S->top++] = stud;
	}
}

studRec pop(StackPtr S)
{
	if(S->top != 0) {
		studRec retStud = S->records[--S->top];
		
		return retStud;
	}
}

Boolean isEmptyStack(Stack S)
{
	return (S.top == 0) ? TRUE : FALSE;
}

Boolean isFullStack(Stack S)
{
	return (S.top == MAX_REC) ? TRUE : FALSE;
}

void displayStack(Stack S)
{
	int i;
	
	printf("TOP IS : %d\n", S.top);
	
	for(i = S.top-1; i >= 0; i--) {
		printf("%-10s | %-20s, %-20s %-5c | %-8s - %2d\n",
			S.records[i].ID,
			S.records[i].name.LN, S.records[i].name.FN, S.records[i].name.MI,
			S.records[i].course, S.records[i].yrLevel
		);
	}
}

//QUEUE FUNCTIONS
void initQueue(QueuePtr Q)
{
	Q->front = 0;
	Q->rear = -1;
}

void enqueue(QueuePtr Q, studRec stud)
{
	if((Q->rear + 2) % MAX_REC != Q->front) {
		Q->rear = (Q->rear + 1) % MAX_REC;
		Q->studs[Q->rear] = stud;
	}
}

void dequeue(QueuePtr Q)
{
	if((Q->rear + 1) % MAX_REC != Q->front) {
		Q->front = (Q->front + 1) % MAX_REC;
	}	
}

void displayQueue(Queue Q)
{
	int i;
	
	for(i = Q.front; i <= Q.rear; i = (i+1) % MAX_REC) {
		printf("%-10s | %-20s, %-20s %-5c | %-8s - %2d\n",
			Q.studs[i].ID,
			Q.studs[i].name.LN, Q.studs[i].name.FN, Q.studs[i].name.MI,
			Q.studs[i].course, Q.studs[i].yrLevel
		);
	}
}

int main()
{
	Lists list;
	initializeStack(&(list.S));
	initQueue(&(list.Q));
	
	push(&(list.S), newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    push(&(list.S), newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    push(&(list.S), newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    push(&(list.S), newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    push(&(list.S), newStudent("45678901", newName("Sarah", "Williams", 'D'), "BS CS", 2));
    push(&(list.S), newStudent("56789012", newName("Christopher", "Brown", 'E'), "BS IT", 2));
    push(&(list.S), newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    push(&(list.S), newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    push(&(list.S), newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    push(&(list.S), newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    push(&(list.S), newStudent("45678901", newName("Sarah", "Williams", 'D'), "BS CS", 2));
    push(&(list.S), newStudent("56789012", newName("Christopher", "Brown", 'E'), "BS IT", 2));
    push(&(list.S), newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    push(&(list.S), newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    push(&(list.S), newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    push(&(list.S), newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    
	studRec popped = pop(&(list.S));
	printf("SUCCESSFULLY POPPED STUDENT WITH ID : %-20s\n\n", popped.ID);
	push(&(list.S), newStudent("45678901", newName("Sarah", "Williams", 'D'), "BS CS", 2));
    push(&(list.S), newStudent("56789012", newName("Christopher", "Brown", 'E'), "BS IT", 2));
    
    displayStack(list.S);
    
    system("pause");
    system("cls");
    
    enqueue(&(list.Q), newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    enqueue(&(list.Q), newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("45678901", newName("Sarah", "Williams", 'D'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("56789012", newName("Christopher", "Brown", 'E'), "BS IT", 2));
    enqueue(&(list.Q), newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    enqueue(&(list.Q), newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("45678901", newName("Sarah", "Williams", 'D'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("56789012", newName("Christopher", "Brown", 'E'), "BS IT", 2));
    enqueue(&(list.Q), newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    enqueue(&(list.Q), newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    enqueue(&(list.Q), newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    
    dequeue(&(list.Q));
    
    printf("LIST FRONT IS AT %2d AND REAR AT %2d\n\n", list.Q.front, list.Q.rear);
    
    displayQueue(list.Q);
	
	return 0;
}
