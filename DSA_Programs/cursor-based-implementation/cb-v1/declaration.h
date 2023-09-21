#ifndef DECLARATION_H
#define DECLARATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4


//DECLARATIONS
typedef char String[50];
typedef int CLIST;

typedef struct {
	String FN, LN;
	char MI;
} Name;

typedef struct {
	int day;
	int month;
	int year;
} Birthdate;

typedef struct {
	String course;
	String dept;
	float gpa;
	int year;
} Info;

typedef struct {
	Name studName;
	Birthdate studBday;
	Info studInfo;
	String status;
	int id;
} Student;

typedef struct {
	Student stud;
	int next;
} Nodes;

typedef struct entry {
	Nodes stud[MAX];
	int avail;	
} LIST;

typedef struct node {
	LIST student;
	int head;
	struct node* next;
} *BLOCK;

//MISCELLANEOUS FUNCTIONS
int check(int boolean);

//STUDENT GENERATION
Student createStudentEntry(Name studName, Birthdate bDay, Info studInfo, String status, int id);
Name createStudentName(String FN, String LN, char MI);
Birthdate createBirthDate(int day, int month, int year);
Info createStudInfo(String course, String dept, float gpa, int year);


//CURSOR BASED PROPER
int initList(LIST* L);
void deallocSpace(LIST* L, int ndx);
int allocSpace(LIST* L);
int insertFirst(LIST* L, int* head, Student student);
int insertLast(LIST* L, int* head, Student student);
int deleteFirst(LIST* L, int *head);
int deleteLast(LIST* L, int *head);
int deleteFirstOccurence(LIST* L, CLIST* head, int id);
int insertSortedByLastName(LIST* L, int *head, Student student);
void displayList(LIST L, int head);

#endif