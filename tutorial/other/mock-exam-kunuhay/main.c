#include "functions.c"

int main()
{
    Roster list;

    //INITIALIZE THE LIST HERE AND PRINT SUCCESSFUL IF RETURNS TRUE BOOLEAN
    system("pause");
    system("cls");

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
    /*
    INSERT STUDENT (Name = GOJO, SATORU MANANANGGAL, Bday = 7/12/1989, enrolledAt = 20, 11, 2019, 
    Course = BS IT, Dept = DCISM, YearLevel = 1, GPA = 1.00, ID = 14369420, Gender = Male 
    */

    //CALL INSERT SORTED FUNCTION HERE

    printf("THIS IS THE NEW LIST OF STUDENTS:\n");
    //CALL DISPLAY NEW LIST

    system("pause");
    system("cls");

    //CALL SORTING FUNCTION HERE (SORT BY ENROLLED DATE) NOTE : YOU CAN USE THE HELPER FUNCTIONS

    printf("THIS IS THE LIST SORTED BY ENROLLED DATE : \n");
    //CALL DISPLAY FUNCTION HERE

    return 0;
}
