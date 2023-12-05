#include<stdio.h>
#include<string.h>
#include"declaration.h"

//HELPER FUNCTIONS
Name createName(String fName, String lName, String mName)
{
    Name name;

    strcpy(name.firstName, fName);
    strcpy(name.lastName, lName);
    strcpy(name.middleName, mName);

    return name;
}
CourseAndYear createCourseAndYear(String course, String dept, int year)
{
    CourseAndYear courseAndYear;

    strcpy(courseAndYear.course, course);
    strcpy(courseAndYear.dept, dept);
    courseAndYear.year = year;

    return courseAndYear;
}
BirthDate createBirthDate(int day, String month, int year)
{
    BirthDate bDay;

    strcpy(bDay.month, month);
    bDay.day = day;
    bDay.year = year;

    return bDay;
}
Student createStudent(Name studName, BirthDate bDay, CourseAndYear courseAndYear, float gpa, int id)
{
    Student stud;

    stud.studName = studName;
    stud.bDay = bDay;
    stud.crsAndYear = courseAndYear;
    stud.gpa = gpa;
    stud.id = id;
    stud.next = -1;

    return stud;
}
int hash(float N)
{
    float number = N;


    if(number < 1.5){
        return 0;
    }
    else if(number < 2 && number >= 1.5){
        return 1;
    }
    else if(number<2.5 && number >=2){
        return 2;
    }
    else if(number <=3 && number >= 2.5){
        return 3;
    }
    else{
        return -1;
    }
    return -1;
}
Section initializeSection()
{
    Section sec;
    int x;

    sec.counter = 0;
    sec.avail = MAX-1;
    sec.head = -1;

    for(x = MAX-1; x >= 0; x--) {
        sec.studentList[x].next = x - 1;
    }

    return sec;
}
void initializeLevel(Level* level)
{
    *level = NULL;
}
void initializeGradeLevel(groupSection G)
{
    int i;
    Level new;
    for(i = 0; i < MAXGRADELEVEL; i++) {
        new = malloc(sizeof(struct level));
        new->link = NULL;
        new->group = initializeSection();
        G[i] = new;
    }
}
Bool isEmpty(Level L)
{
    Bool check;

    return check = (L == NULL) ? TRUE : FALSE;
}
void checkOperation(Bool check) 
{
    check == TRUE ? printf("OPERATION SUCCESSFUL!\n") : printf("ERROR IN THE OPERATION\n");
}
int allocSpace(Section* S)
{
    int retVal = -1;
    if(S->avail != -1) {
       retVal = S->avail;
       S->avail = S->studentList[retVal].next;
    }

    return retVal;
}
Bool deallocSpace(Section* S, int index)
{
    Bool retVal = FALSE;
    if(S->head != -1 && index < MAX) {
        S->studentList[index].next = S->avail;
        S->avail = index;
        retVal = TRUE;
    }
    return retVal;
}

//NEEDS IMPLEMENTATION
void insertSection(Section* S, Student stud)
{
    if (S->avail != -1) { // Check if there is available space in the section.
        int* trav;

        for (trav = &(S->head); *trav != -1; trav = &S->studentList[*trav].next) {}

        int temp = allocSpace(S); 
        if (temp != -1) { 
            S->studentList[temp] = stud;
            S->studentList[temp].next = *trav;

            *trav = temp;
            S->counter++;
        }
    }
}

Bool push(Level* L, Section S)
{
    Bool retVal = FALSE;

    Level temp = (Level) malloc(sizeof(struct level));
    if(temp != NULL) {
        temp->link = *L;
        temp->group = S;
        
        *L = temp;
        retVal = TRUE;
    }

    return retVal;
}

Bool pop(Level* L)
{
    Bool check = FALSE;
    Level temp;

    if(isEmpty(*L) == FALSE) {
        temp = *L;
        *L = temp->link;
        free(temp);
        check = TRUE;
    }
    return check;
}

void displayGroups(Level* L)
{
    int x, y, z;
    Level temp;

    initializeLevel(&temp);

    for(y = 1; isEmpty(*L) == FALSE; y++) {
        printf("GROUP %02d : \n", y);
        for(x = (*L)->group.head, z = (*L)->group.counter; z > 0; x = (*L)->group.studentList[x].next, z--) {
             printf("%11d | %20s, %20s %c. | %02d/%-10s/%04d | %4s %4s - %02d | %02.2f |\n", 
             (*L)->group.studentList[x].id, (*L)->group.studentList[x].studName.lastName,
             (*L)->group.studentList[x].studName.firstName, (*L)->group.studentList[x].studName.middleName[0],
             (*L)->group.studentList[x].bDay.day, (*L)->group.studentList[x].bDay.month, (*L)->group.studentList[x].bDay.year,
             (*L)->group.studentList[x].crsAndYear.dept, (*L)->group.studentList[x].crsAndYear.course, 
             (*L)->group.studentList[x].crsAndYear.year, (*L)->group.studentList[x].gpa);
        }
        push(&temp, (*L)->group);
        pop(L);
    }

    for(; isEmpty(temp) == FALSE; ) {
        push(L, temp->group);
        pop(&temp);
    }
}

Bool addListToGradeLevel(Level L, groupSection G)
{
    int travC, hashidx, i;
    Bool retval = FALSE;
    Level travD, new;

    while(L != NULL) {
        for(travC = L->group.head; travC != -1; travC = L->group.studentList[travC].next){
            hashidx = hash(L->group.studentList[travC].gpa);
            travD = G[hashidx];
            insertSection(&travD->group, L->group.studentList[travC]);
            retval = TRUE;
        }
        L = L->link;
    }
    return retval;
}
