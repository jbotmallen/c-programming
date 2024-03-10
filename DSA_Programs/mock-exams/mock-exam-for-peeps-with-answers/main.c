#include "functions.c"

int main()
{
    Combo C;

    /*INITIALIZE COMBO
        Set the list and array to NULL and 0, respectively.
        It takes in a pointer to a Combo struct. Call the
        function initCombo below.
    */
    initCombo(&C);
    system("pause");
    system("cls");

    /*CREATE THE LIST AND ARRAY
        An array of students have been prepared for in
        the createStudent function. The students are then
        divided into two groups: those who enrolled in the
        first semester (from August 8, 2023 - December 20, 2023)
        and those who enrolled in the second
        semester (from January 1, 2024 - May 20, 2024).
        The students who enrolled in the first
        semester are added to the list while the students
        who enrolled in the second semester are added to
        the array. Make use of the insertLastList and
        insertLastArray functions to add the students to
        the list and array, respectively.
        It takes in a pointer to a Combo struct.
        Call the function createList below.
    */
    createList(&C);
    system("pause");
    system("cls");

    /*DISPLAY THE COMBO
        The students who enrolled in the first semester are
        displayed first, followed by the students who enrolled
        in the second semester. It takes in a Combo struct.
        Call the function displayCombo below.
    */
    displayCombo(C);
    system("pause");
    system("cls");

    /*CREATE A NEW HEAP AND INITIALIZE IT
        Create a new heap and initialize it. The heap is
        initially empty. It takes in a pointer to a StudentHeap
        struct and a pointer to a HEAD. Call the function
        initHeap below.
    */
    StudentHeap H;
    HEAD head;
    initHeap(&H, &head);
    system("pause");
    system("cls");

    /*TRANSFER 4TH YEARS TO HEAP
        Some of the 4th years are included in the list. Transfer
        them to the heap. The students in the heap are sorted
        based on their GPA. It takes in a pointer to a Combo
        struct. Call the function transferToHeap below.
    */
    transferToHeap(&C, &H, &head);
    system("pause");
    system("cls");

    /*DISPLAY THE HEAP AND LIST
        Display the students in the heap. It takes in a StudentHeap
        struct. Call the function displayHeap below. Display the
        students in the list. It takes in a Combo struct. Call the
        function displayCombo below.
    */
    displayHeap(H, head);
    displayCombo(C);
}