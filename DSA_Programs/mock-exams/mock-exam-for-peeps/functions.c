#include "header.h"

// HELPER FUNCTIONS
void initList(ListPtr *L)
{
    *L = NULL;
}
void initArray(Array *A)
{
    A->count = 0;
}
void initHeap(StudentHeap *H, HEAD *head)
{
    int i;
    *head = -1;

    for (i = MAX_ARR - 1; i >= 0; i--)
    {
        H->studHeap[i].link = i - 1;
    }

    H->avail = MAX_ARR - 1;

    printf("Heap initialized.\n");
}
int allocSpace(StudentHeap *H)
{
    int ret = H->avail;

    if (ret != -1)
    {
        H->avail = H->studHeap[ret].link;
    }

    return ret;
}
Name createName(char *FN, char *LN, char MI)
{
    Name temp;
    strcpy(temp.FN, FN);
    strcpy(temp.LN, LN);
    temp.MI = MI;
    return temp;
}
Date createDate(int month, int day, int year)
{
    Date temp;
    temp.month = month;
    temp.day = day;
    temp.year = year;
    return temp;
}
Student createStudent(Name studName, Date enrolledAt, int yearLevel, float gpa)
{
    Student temp;
    temp.studName = studName;
    temp.enrolledAt = enrolledAt;
    temp.yearLevel = yearLevel;
    temp.gpa = gpa;
    return temp;
}
void printLine()
{
    printf("=========================================================================\n");
}

// REQUIREMENT FUNCTIONS
void insertLastList(ListPtr *L, Student S)
{
    ListPtr *trav;

    for (trav = L; *trav != NULL; trav = &(*trav)->next)
    {
    }

    if (*trav == NULL)
    {
        ListPtr temp = (ListPtr)malloc(sizeof(List));
        if (temp != NULL)
        {
            temp->stud = S;
            temp->next = NULL;
            *trav = temp;
        }
    }
}
void insertLastArray(Array *A, Student S)
{
    if (A->count < MAX_ARR)
    {
        A->studArr[A->count++] = S;
    }
    else
    {
        printf("Array is full.\n");
    }
}

// PROBLEM FUNCTIONS
void initCombo(Combo *C)
{
    /* Set the list and array to NULL and 0, respectively.
        Write your code here!
    */
}

void createList(Combo *C)
{
    Student temp[MAX_ARR] = {
        createStudent(createName("Juan", "Dela Cruz", 'A'), createDate(1, 1, 2024), 1, 3.0),
        createStudent(createName("Mercy", "Samen", 'J'), createDate(12, 10, 2023), 2, 3.5),
        createStudent(createName("Jesus", "Delos Santos", 'I'), createDate(11, 9, 2023), 1, 3.0),
        createStudent(createName("Peter", "Jenudo", 'D'), createDate(4, 4, 2024), 4, 3.5),
        createStudent(createName("Marci", "Palabre", 'F'), createDate(8, 6, 2023), 2, 3.5),
        createStudent(createName("Marc", "Dela Cruz", 'E'), createDate(5, 5, 2024), 1, 3.0),
        createStudent(createName("Manny", "Pacquiao", 'H'), createDate(10, 8, 2023), 4, 3.0),
        createStudent(createName("Lovely", "Babel", 'G'), createDate(9, 7, 2023), 3, 3.0),
        createStudent(createName("John", "Tamad", 'C'), createDate(3, 3, 2024), 3, 3.0),
        createStudent(createName("Pedro", "Penduko", 'B'), createDate(2, 2, 2024), 2, 3.5)};

    // Add students to the list and array
    //Write your code here!
}

void displayCombo(Combo C)
{
    // Display the students in the list and array
    //Write your code here!
}

void insertSortedHeap(StudentHeap *H, HEAD *head, Student S)
{
    // Insert the student in the heap and sort it based on GPA
    //Write your code here!
}

void transferToHeap(Combo *C, StudentHeap *H, HEAD *head)
{
    // Transfer the 4th year students to the heap
    //Write your code here!
}

void displayHeap(StudentHeap H, HEAD head)
{
    // Display the students in the heap
    //Write your code here!
}