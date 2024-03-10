#include<stdio.h>
 #include"arrayStack.h"
//#include"linkedlistStack.h"

int main()
{
    Stack list;

    //INITIALIZATION OF STACK
    initialize(&list) ? printf("\n\nSUCCESSFULLY INITIALIZED THE STACK!\n\n") : printf("\n\nERROR IN INITIALIZATION\n\n");
    pauseAndClear();

    //POPULATION OF STACK
    populateList(&list) ? printf("\n\nSUCCESSFULLY POPULATED THE STACK!\n\n") : printf("\n\nERROR IN POPULATION\n\n");
    pauseAndClear();

    display(list);
    pauseAndClear();
    
    //INSERT AT THE END OF STACK
    insertBottom(&list, 53) ? printf("\n\nSUCCESSFULLY INSERTED AT THE BOTTOM!\n\n") : printf("\n\nERROR IN INSERTION\n\n");
    pauseAndClear();

    display(list);
    printf("\n%10s%10s\n| TOP ELEM OF THE LIST : %d |\n%10s%10s\n", line, line, top(list), line, line);
    return 0;
}