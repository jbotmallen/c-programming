#include"functions.c"
#include"declaration.h"

int main()
{
    DICTIONARY d;

    init(&d);

    insert(&d, 67);
    insert(&d, 23);
    insert(&d, 57);
    insert(&d, 31);
    insert(&d, 32);
    insert(&d, 11);
    insert(&d, 66);
    insert(&d, 35);

    display(d);

    system("pause");
    system("cls");

    deleteMem(&d, 31);
    deleteMem(&d, 57);
    deleteMem(&d, 99);

    display(d);

    return 0;
}