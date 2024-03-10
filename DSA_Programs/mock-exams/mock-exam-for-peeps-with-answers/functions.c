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
    initList(&C->list);
    initArray(&C->arr);

    printf("Combo initialized.\n");
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

    int i;

    for (i = 0; i < MAX_ARR; i++)
    {
        if (temp[i].enrolledAt.month < 6)
        {
            insertLastList(&C->list, temp[i]);
        }
        else
        {
            insertLastArray(&C->arr, temp[i]);
        }
    }

    printf("SUCCESSFULLY CREATED LIST AND ARRAY.\n");
}

void displayCombo(Combo C)
{
    if (C.list != NULL)
    {
        ListPtr temp;

        printf("Enrolled students for the first semester:\n");
        printf("%-20s, %20s %5c. - %10s\n", "Last Name", "First Name", 'M', "Year Level");
        printLine();

        for (temp = C.list; temp != NULL; temp = temp->next)
        {
            printf("%-20s, %20s %5c. - %10d\n", temp->stud.studName.LN, temp->stud.studName.FN, temp->stud.studName.MI, temp->stud.yearLevel);
        }
    }
    else
    {
        printf("List is empty.\n");
    }

    printf("\n");

    if (C.arr.count > 0)
    {
        int i;

        printf("Enrolled students for the second semester:\n");
        printf("%-20s, %20s %5c. - %10s\n", "Last Name", "First Name", 'M', "Year Level");
        printLine();

        for (i = 0; i < C.arr.count; i++)
        {
            printf("%-20s, %20s %5c. - %10d\n", C.arr.studArr[i].studName.LN, C.arr.studArr[i].studName.FN, C.arr.studArr[i].studName.MI, C.arr.studArr[i].yearLevel);
        }
    }
    else
    {
        printf("Array is empty.\n");
    }
}

void insertSortedHeap(StudentHeap *H, HEAD *head, Student S)
{
    int temp = allocSpace(H);
    if (temp != -1)
    {
        int *trav;

        for (trav = head; *trav != -1 && H->studHeap[*trav].student.gpa < S.gpa; trav = &H->studHeap[*trav].link)
        {
        }

        if (*trav == -1 || H->studHeap[*trav].student.gpa >= S.gpa)
        {
            H->studHeap[temp].student = S;
            H->studHeap[temp].link = *trav;
            *trav = temp;

            printf("SUCCESSFULLY INSERTED STUDENT : %20s TO HEAP.\n", S.studName.LN);
        }
    }
}

void transferToHeap(Combo *C, StudentHeap *H, HEAD *head)
{
    if (C->list != NULL)
    {
        ListPtr *trav;

        for (trav = &(C)->list; *trav != NULL;)
        {
            if ((*trav)->stud.yearLevel == 4)
            {
                insertSortedHeap(H, head, (*trav)->stud);
                ListPtr temp = *trav;
                *trav = temp->next;
                free(temp);
            }
            else
            {
                trav = &(*trav)->next;
            }
        }
    }

    if (C->arr.count > 0)
    {
        int i;

        for (i = 0; i < C->arr.count; i++)
        {
            if (C->arr.studArr[i].yearLevel == 4)
            {
                insertSortedHeap(H, head, C->arr.studArr[i]);
                memmove(&C->arr.studArr[i], &C->arr.studArr[i + 1], (C->arr.count - i - 1) * sizeof(Student));
                C->arr.count--;
            }
        }
    }

    printf("SUCCESSFULLY TRANSFERRED 4TH YEAR STUDENTS TO HEAP.\n");
}

void displayHeap(StudentHeap H, HEAD head)
{
    int trav;

    printf("Students in the heap:\n");
    printf("%-20s, %20s %5c. - %10s\n", "Last Name", "First Name", 'M', "GPA");
    printLine();

    for (trav = head; trav != -1; trav = H.studHeap[trav].link)
    {
        printf("%-20s, %20s %5c. - %10.2f\n", H.studHeap[trav].student.studName.LN, H.studHeap[trav].student.studName.FN, H.studHeap[trav].student.studName.MI, H.studHeap[trav].student.gpa);
    }

    printLine();
}