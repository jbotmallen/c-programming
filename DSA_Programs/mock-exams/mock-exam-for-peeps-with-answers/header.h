#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_ARR 10
#define MAX_STR 30

typedef enum {
    FALSE, TRUE
} BOOLEAN;

typedef enum {
    FIRST, SECOND
} SEMESTER;

typedef struct {
    char FN[MAX_STR];
    char LN[MAX_STR];
    char MI;
} Name;

typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    Name studName;
    Date enrolledAt;
    int yearLevel;
    float gpa;
} Student;

typedef struct node {
    Student stud;
    struct node *next;
} List, *ListPtr;

typedef struct {
    Student studArr[MAX_ARR];
    int count;
} Array;

typedef struct {
    ListPtr list;
    Array arr;
} Combo;

typedef struct {
    Student student;
    int link;
} StudentNode;

typedef struct {
    StudentNode studHeap[MAX_ARR];
    int avail;
} StudentHeap;

typedef int HEAD;

// Function prototypes

//HELPER FUNCTIONS
void initList(ListPtr *L);
void initArray(Array *A);
void initHeap(StudentHeap *H, HEAD *head);
int allocSpace(StudentHeap *H);
Name createName(char *FN, char *LN, char MI);
Date createDate(int month, int day, int year);
Student createStudent(Name studName, Date enrolledAt, int yearLevel, float gpa);
void printLine();


//PROBLEM FUNCTIONS
void initCombo(Combo *C);
void createList(Combo *C);
void displayCombo(Combo C);

//ADDITIONAL FUNCTIONS (REQUIRED)
void insertLastArray(Array *A, Student S);
void insertLastList(ListPtr *L, Student S);
void insertSortedHeap(StudentHeap *H, HEAD *head, Student S);
void transferToHeap(Combo *C, StudentHeap *H, HEAD *head);
void displayHeap(StudentHeap H, HEAD head);
