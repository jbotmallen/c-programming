#include"declaration.h"
#include <Windows.h>

void init(Dictionary D)
{
    int x;

    for(x = 0; x < MAX; x++) {
        D[x] = NULL;
    }
}

int hash(int num)
{
    return num % 10;
}

void insert(Dictionary D, int elem)
{
    int x = hash(elem);

    LIST* trav;
    for(trav = &D[x]; *trav != NULL && (*trav)->elem < elem; trav = &D[x]->next){}

    if(*trav == NULL || (*trav)->elem != elem) {
        LIST temp = (LIST) malloc(sizeof(nodeType));
        if(temp != NULL) {
            temp->elem = elem;
            temp->next = *trav;

            *trav = temp;
        }
    }
}

void deleteElem(Dictionary D, int elem)
{
    int x = hash(elem);
    LIST* trav;

    for(trav = D+x; *trav != NULL && (*trav)->elem < elem; trav = &(*trav)->next) {}

    if(*trav != NULL && (*trav)->elem == elem) {
        LIST temp = (LIST) malloc(sizeof(nodeType));

        if(temp != NULL) {
            temp = *trav;
            *trav = temp->next;
            free(temp);
        } 
    }
}

void display(Dictionary D)
{
    int x;

    for(x = 0; x < MAX; x++) {
        LIST trav;

        printf("ELEMENTS IN ROW %d : ", x);

        if(D[x] == NULL) {
            printf("ROW IS EMPTY!");
            Sleep(1000);
            
        } else {
            for(trav = D[x]; trav != NULL; trav = trav->next) {
                printf("| %d |", trav->elem);
                Sleep(1000);
                if(trav->next != NULL)
                printf("->");
            }
        }
        printf("\n==============================================\n");
    }

    system("pause");
    system("cls");
}