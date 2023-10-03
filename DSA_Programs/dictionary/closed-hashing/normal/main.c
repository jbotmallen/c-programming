#include"declarations.h"
#include"functions.c"

int main()
{
    DICTIONARY d;

    init(d);
    populate(d);
    display(d);

    deleteElem(d, 99);//TRY TO DELETE SOMETHING THAT DOESN'T EXIST
    deleteElem(d, 27); //DELETE SOMETHING
    deleteElem(d, 35);//DELETE AT SOMEWHERE RECENTLY DELETED
    display(d);

    int check = 0;
    check += member(d, 88);

    check >= 0 ? printf("IS A MEMBER AT ROW : %d\n", check) : printf("NOT A MEMBER!");

    return 0;
}