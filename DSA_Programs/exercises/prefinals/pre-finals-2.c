#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VH_MAX 0xFF
#define MAX 0xA

typedef struct {
    char FN[24], LN[16], MI;
} nameType;

typedef struct {
    char ID[9];
    nameType name;
    char course[8];
    int yrLevel;
} studRec;

typedef struct {
    studRec stud;
    int link;
} CBnode;

typedef struct {
    CBnode heap[VH_MAX];
    int avail;
} *Vheap, VHeap;

typedef struct node {
    studRec data[MAX];
    int studCtr;
} *ArrayList;

typedef int CursorList;

void deallocSpace(Vheap VH, int idx) 
{
	if(idx > -1 && idx < MAX) {
		VH->heap[idx].link = VH->avail;
		VH->avail = idx;
	}
}

int allocSpace(Vheap VH)
{
	int retval = VH->avail;
	
	if(retval != -1) VH->avail = VH->heap[retval].link;
	
	return retval;	
}

int transferToHeap(Vheap vh, CursorList* h, ArrayList A)
{
	int counter, x;
	int* trav;
	
	for(counter = 0, x = 0; x < A->studCtr; x++) {
		for(trav = h; *trav != -1 && strcmp(vh->heap[*trav].stud.ID, A->data[x].ID) < 0; trav = &vh->heap[*trav].link) {}
		
		if(*trav == -1 || strcmp(vh->heap[*trav].stud.ID, A->data[x].ID) != 0) {
			int temp = allocSpace(vh);
			
			if(temp != -1) {
				vh->heap[temp].stud = A->data[x];
				vh->heap[temp].link = *trav;
				*trav = temp;
				counter++;
			}
		}
	}
	
	return counter;
}

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

void initialize(Vheap VH, CursorList* H)
{
    int i;
    
    for(i = VH_MAX-1; i >= 0; i--)
        VH->heap[i].link = i - 1;
      
    VH->avail = VH_MAX-1;
    *H = -1;
}

void initializeList(ArrayList* A)
{
	ArrayList temp = (ArrayList) malloc(sizeof(struct node));
	
	if(temp != NULL) {
		temp->studCtr = 0;
	}
	
	*A = temp;
}

void insertNewStudent(ArrayList* A, studRec stud)
{
	if((*A)->studCtr < MAX) {
		(*A)->data[(*A)->studCtr++] = stud;
	}
}

void display(VHeap VH, CursorList H)
{
	int trav;
	
	printf("STUDENTS IN THE VHEAP: \n");
	for(trav = H; trav != -1; trav = VH.heap[trav].link) {
		printf("%-10s | %-20s, %-20s %-5c | %-8s - %2d\n",
			VH.heap[trav].stud.ID, 
			VH.heap[trav].stud.name.LN, VH.heap[trav].stud.name.FN, VH.heap[trav].stud.name.MI,
			VH.heap[trav].stud.course, VH.heap[trav].stud.yrLevel
		);
	}
}

void displayArrayList(ArrayList A)
{
	int i;
	
	for(i = 0; i < A->studCtr; i++) {
		printf("%-10s | %-20s, %-20s %-5c | %-8s - %2d\n",
			A->data[i].ID,
			A->data[i].name.LN, A->data[i].name.FN, A->data[i].name.MI,
			A->data[i].course, A->data[i].yrLevel
		);
	}
}

int main()
{
	ArrayList list;
	VHeap heap;
	CursorList head;
    
    initializeList(&list);
    initialize(&heap, &head);
    
    insertNewStudent(&list, newStudent("19104099", newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    insertNewStudent(&list, newStudent("12345678", newName("John", "Smith", 'A'), "BS CS", 2));
    insertNewStudent(&list, newStudent("23456789", newName("Emily", "Johnson", 'B'), "BS IT", 2));
    insertNewStudent(&list, newStudent("34567890", newName("Michael", "Davis", 'C'), "BS CS", 2));
    insertNewStudent(&list, newStudent("45678901", newName("Sarah", "Williams", 'D'), "BS CS", 2));
    insertNewStudent(&list, newStudent("56789012", newName("Christopher", "Brown", 'E'), "BS IT", 2));
    insertNewStudent(&list, newStudent("67890123", newName("Jessica", "Miller", 'F'), "BS CS", 2));
    insertNewStudent(&list, newStudent("78901234", newName("Matthew", "Wilson", 'G'), "BS IT", 2));
    insertNewStudent(&list, newStudent("89012345", newName("Lauren", "Jones", 'H'), "BS CS", 2));
    insertNewStudent(&list, newStudent("90123456", newName("David", "Taylor", 'I'), "BS CS", 2));
    insertNewStudent(&list, newStudent("12345677", newName("Olivia", "Anderson", 'J'), "BS IT", 2));
    
    displayArrayList(list);
    system("pause");
    system("cls");
    
    displayArrayList(list);
    system("pause");
    system("cls");
    
    int newCounter = transferToHeap(&heap, &head, list);
    printf("THE VIRTUAL HEAP HAS %2d ENTRIES.\n\n", newCounter);
    display(heap, head);
    
    return 0;
}
