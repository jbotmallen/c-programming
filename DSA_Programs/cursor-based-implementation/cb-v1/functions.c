#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"declaration.h"

//OTHER FUNCTIONS
Birthdate createBirthDate(int day, int month, int year)
{
	Birthdate bday;

	bday.day = day;
	bday.month = month;
	bday.year = year;

	return bday;
}

Name createStudentName(String FN, String LN, char MI)
{
	Name studName;

	strcpy(studName.FN, FN);
	strcpy(studName.LN, LN);
	studName.MI = MI;

	return studName;
}

Info createStudInfo(String course, String dept, float gpa, int year)
{
	Info newInfo;

	strcpy(newInfo.course, course);
	strcpy(newInfo.dept, dept);

	newInfo.gpa = gpa;
	newInfo.year = year;

	return newInfo;
}

Student createStudentEntry(Name studName, Birthdate bDay, Info studInfo, String status, int id)
{
	Student stud;

	strcpy(stud.status, status);
	stud.studBday = bDay;
	stud.studInfo = studInfo;
	stud.studName = studName;
	stud.id = id;

	return stud;
}

int check(int boolean)
{
	switch (boolean)
	{
	case 1:
		printf("SUCCESSFULLY INITIALIZED THE LIST OF STUDENTS!\n\n");
		break;

	case 2:
		printf("SUCCESSFULLY ADDED TO THE LIST OF STUDENTS!\n\n");
		break;

	case 3:
		printf("SUCCESSFULLY DELETED FROM THE LIST OF STUDENTS!\n\n");
		break;
	
	default:
		printf("ERROR IN THE OPERATION\n");
		break;
	}
}

//CURSOR-BASED PROPER
int initList(LIST* L)
{
	int x, retval = 0, temp = MAX-1;
	
	for(x = 0; x < temp; x++){
		L->stud[x].next = x + 1;
	}

	L->stud[temp].next = -1;
	L->avail = 0;
	
	return retval = 1;
}

void deallocSpace(LIST* L, int ndx)
{
	if(ndx >= 0 && ndx < MAX) {
		L->stud[ndx].next = L->avail;
		L->avail = ndx;
	}
}

int allocSpace(LIST* L)
{
	int retval;
	
	retval = L->avail;
	if(retval != -1){
		L->avail = L->stud[L->avail].next;
	}
	
	return retval;
}

//INSERT FUNCTIONS
int insertFirst(LIST* L, int* head, Student student)
{
	int retval = 0;

	if(L->avail != -1) {
		int first = allocSpace(L);

		L->stud[first].stud = student;
		L->stud[first].next = *head;
		*head = first;
		retval = 2;
	}

	return retval;
}

int insertLast(LIST* L, int* head, Student student)
{
	int retval = 0;

	if(L->avail != -1) {
		CLIST temp = allocSpace(L);
		
		L->stud[temp].stud = student;
		L->stud[temp].next = -1;

		CLIST* x;
		for(x = head; L->stud[*x].next != -1; x = &L->stud[*x].next) {}
		L->stud[*x].next = temp;
		
		retval = 2;

	}

	return retval;
}

int insertSortedByLastName(LIST* L, int *head, Student student)
{
	int retval = 0;

	if(L->avail != -1)
	{
		CLIST x;

		for(x = *head; x != -1 && strcmp(L->stud[x].stud.studName.LN, student.studName.LN) < 0; x = L->stud[x].next) {}
		if(x != -1) {
			CLIST temp = allocSpace(L);

			L->stud[temp].stud = L->stud[x].stud;
			L->stud[x].stud = student;
			L->stud[temp].next = L->stud[x].next;
			L->stud[x].next = temp;
		} else {
			insertLast(L, head, student);
		}
		retval = 2;
	}

	return retval;
}

//DELETE FUNCTIONS
int deleteFirst(LIST* L, int *head)
{
	int retval = 0;

	if(*head != -1) {
		CLIST temp;

		temp = L->stud[*head].next;
		deallocSpace(L, *head);
		*head = temp;

		retval = 3;
	}

	return retval;
}

int deleteLast(LIST* L, int *head)
{
	int retval = 0;

	if(*head != -1) {
		CLIST x, y = -1;

		for(x = *head; L->stud[x].next != -1; y = x, x = L->stud[x].next) {}

		if(y != -1) {
			deallocSpace(L, x);
			L->stud[y].next = -1;
		} else {
			deallocSpace(L, *head);
			*head = -1;
		}
		
		retval = 3;
	}

	return retval;
}

int deleteFirstOccurence(LIST* L, CLIST* head, int id)
{
	int retVal = 0;

	if(*head != -1) {
		CLIST* trav;

		for(trav = head; *trav != -1 && L->stud[*trav].stud.id != id; trav = &L->stud[*trav].next){}

		if(*trav != -1) {
			CLIST temp = *trav;
			*trav = L->stud[temp].next;
			deallocSpace(L, temp);
			retVal = 3;
		}
	}

	return retVal;
}

//PRINT DETAILS
void displayList(LIST L, int head)
{
	system("pause");
	system("cls");

	CLIST x;

	if(head != -1){
		printf("%12s | %12s | %20s, %20s %6s | %2s/%2s/%4s | %10s %10s | %4s | %20s\n", 
		"ID NUMBER", "YEAR LEVEL", "LAST NAME", "FIRST NAME", "MI", "DD", "MM", "YYYY", "COURSE", "DEPT", "GPA", "ENROLMENT STATUS");

		for(x = head; x != -1; x = L.stud[x].next) {
			printf("%12d | %12d | %20s, %20s %5c. | %02d/%02d/%04d | %10s %10s | %4.2f | %20s\n", L.stud[x].stud.id, L.stud[x].stud.studInfo.year,
			L.stud[x].stud.studName.LN, L.stud[x].stud.studName.FN, L.stud[x].stud.studName.MI, L.stud[x].stud.studBday.day,
			L.stud[x].stud.studBday.month, L.stud[x].stud.studBday.year, L.stud[x].stud.studInfo.course, L.stud[x].stud.studInfo.dept,
			L.stud[x].stud.studInfo.gpa, L.stud[x].stud.status);
		}
	} else {
		printf("=========================================\n\n%30s\n\n=========================================", "THERE ARE NO ELEMENTS IN THE LIST!");
	}

	printf("\n\n");
}