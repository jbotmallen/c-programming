#include"functions.c"
#include"declaration.h"

int main()
{
    Dictionary dc;

    init(dc); //INITIALIZES THE DICTIONARY ROWS TO NULL

    insert(dc, 19); //INSERT FIRST
    insert(dc, 79); //INSERT LAST
    insert(dc, 25); //INSERT FIRST
    insert(dc, 33); //INSERT FIRST
    insert(dc, 103); //INSERT LAST
    insert(dc, 46); //INSERT FIRST
    insert(dc, 43); //INSERT MIDDLE

    printf("==================================\nDICTIONARY BEFORE DELETING : \n==================================\n");
    display(dc);

    deleteElem(dc, 103); //DELETE LAST
    deleteElem(dc, 19); //DELETE FIRST
    deleteElem(dc, 15); //DELETE DOES NOT EXIST
    deleteElem(dc, 88); //DELETE FROM EMPTY

    printf("==================================\nDICTIONARY AFTER DELETING : \n==================================\n");
    display(dc);

    return 0;
}