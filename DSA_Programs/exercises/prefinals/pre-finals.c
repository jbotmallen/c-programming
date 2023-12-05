#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VH_MAX 0xFF
#define MAX 0xA

typedef struct {
    char FN[24], LN[16], MI;
} nameType;

typedef struct {
    unsigned int ID;
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

ArrayList segregate(char course[], Vheap VH, CursorList* H)
{
    if(*H != -1) {
    	int* trav;
    	ArrayList A = (ArrayList) malloc(sizeof(struct node));
    	A->studCtr = 0;
    	
    	for(trav = H; *trav != -1; trav = &VH->heap[*trav].link) {
    		if(strcmp(VH->heap[*trav].stud.course, course) == 0) {
    			A->data[A->studCtr++] = VH->heap[*trav].stud;
    			int temp = *trav;
    			*trav = VH->heap[temp].link;
    			deallocSpace(VH, temp);
			}
		}
		
		return A;
	}
}

nameType newName(char FN[], char LN[], char MI)
{
	nameType name;
	
	strcpy(name.FN, FN);
	strcpy(name.LN, LN);
	name.MI = MI;
	
	return name;
}

studRec newStudent(unsigned int ID, nameType name, char course[], int yrLevel)
{
	studRec stud;
	
	stud.ID = ID;
	stud.name = name;
	strcpy(stud.course, course);
	stud.yrLevel = yrLevel;
	
	return stud;
}

int allocSpace(Vheap VH)
{
	int retval = VH->avail;
	
	if(retval != -1) VH->avail = VH->heap[retval].link;
	
	return retval;	
}

void initialize(Vheap VH, CursorList* H)
{
    int i;
    
    for(i = VH_MAX-1; i >= 0; i--)
        VH->heap[i].link = i - 1;
      
    VH->avail = VH_MAX-1;
    *H = -1;
}

void insertNewStudent(Vheap VH, CursorList* H, studRec stud)
{
	int* trav;
	
	for(trav = H; *trav != -1; trav = &VH->heap[*trav].link) {}
	
	if(*trav == -1) {
		int temp = allocSpace(VH);
		
		if(temp != -1) {
			VH->heap[temp].stud = stud;
			VH->heap[temp].link = *trav;
			*trav = temp;
		}
	}
}

void display(VHeap VH, CursorList H)
{
	int trav;
	
	printf("STUDENTS IN THE VHEAP: \n");
	for(trav = H; trav != -1; trav = VH.heap[trav].link) {
		printf("%-10d | %-20s, %-20s %-5c | %-8s - %2d\n",
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
		printf("%-10d | %-20s, %-20s %-5c | %-8s - %2d\n",
			A->data[i].ID,
			A->data[i].name.LN, A->data[i].name.FN, A->data[i].name.MI,
			A->data[i].course, A->data[i].yrLevel
		);
	}
}

int main()
{
    CursorList head;
    VHeap vh;
    
    initialize(&vh, &head);
    insertNewStudent(&vh, &head, newStudent(19104099, newName("MARK ALLEN", "JUGALBOT", 'P'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(12345678, newName("John", "Smith", 'A'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(23456789, newName("Emily", "Johnson", 'B'), "BS IT", 2));
    insertNewStudent(&vh, &head, newStudent(34567890, newName("Michael", "Davis", 'C'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(45678901, newName("Sarah", "Williams", 'D'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(56789012, newName("Christopher", "Brown", 'E'), "BS IT", 2));
    insertNewStudent(&vh, &head, newStudent(67890123, newName("Jessica", "Miller", 'F'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(78901234, newName("Matthew", "Wilson", 'G'), "BS IT", 2));
    insertNewStudent(&vh, &head, newStudent(89012345, newName("Lauren", "Jones", 'H'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(90123456, newName("David", "Taylor", 'I'), "BS CS", 2));
    insertNewStudent(&vh, &head, newStudent(12345677, newName("Olivia", "Anderson", 'J'), "BS IT", 2));
    
    display(vh, head);
    system("pause");
    system("cls");
    
    ArrayList arr = segregate("BS IT", &vh, &head);
    
    display(vh, head);
    system("pause");
    system("cls");
    
    displayArrayList(arr);
    
    return 0;
}
