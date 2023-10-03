#include "functions.c"
#include "declaration.h"

int main()
{
    Roster list;

    //INITIALIZE THE
    initialize(&list) == TRUE ? printf("SUCCESSFULLY INITIALIZED THE LIST!\n\n") : printf("ERROR IN INITIALIZATION!\n\n");

    //FIX POPULATE LIST
    list = populate();
    system("pause");
    system("cls");

    //DISPLAY CURRENT LIST
    printf("THIS IS THE CURRENT LIST OF STUDENTS:\n");
    //CALL DISPLAY OF CURRENT LIST HERE
    displayList(list);
    system("pause");
    system("cls");

    //CREATE FUNCTION TO GET LIST OF LATE ENROLLEES
    Roster listOfLateEnrollees;
    //CALL FUNCTION FOR GETTING LATE ENROLLEES HERE
    listOfLateEnrollees = getListOfLateEnrollees(list, 10);

    //DISPLAY LIST OF LATE ENROLLEES
    printf("THIS IS THE LIST OF LATE ENROLLEES:\n");
    //CALL DISPLAY OF LATE ENROLLEES HERE
    displayList(listOfLateEnrollees);
    system("pause");
    system("cls");

    //CREATE FUNCTION TO ADD A NEW STUDENT TO THE SORTED LIST (BASE ON STUDENT LAST NAME)
    Student newEntry = createStudent(createName("SATORU", "GOJO", "MANANANGGAL"), createDate(25, 7, 2001), createDate(20, 11, 2019), createEntry("BS IT", "DCISM", 1), 2.40, 14369420, 'F');
    //CALL INSERT SORTED FUNCTION HERE
    addToSortedList(newEntry, &list) == TRUE ? printf("STUDENT SUCCESSFULLY ADDED!\n") : printf("ERROR IN ADDING STUDENT\n");

    //CALL DISPLAY NEW LIST
    printf("THIS IS THE NEW LIST OF STUDENTS:\n");
    displayList(list);
    system("pause");
    system("cls");

    //CALL SORTING FUNCTION HERE
    sortedByEnrolledDate(&list) == TRUE ? printf("SUCCESSFULLY SORTED LIST BY ENROLLED DATE!\n") : printf("FAILURE IN THE OPERATION\n");

    printf("THIS IS THE LIST SORTED BY ENROLLED DATE : \n");
    //CALL DISPLAY FUNCTION HERE
    displayList(list);
    system("pause");
    system("cls");

    return 0;
}
