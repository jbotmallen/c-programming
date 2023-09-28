#include<stdio.h>
#define MAX 3

typedef int CLIST;

typedef struct { 
    int num;
    int next;
} Nodes;

typedef struct {
    Nodes elements[MAX];
    int avail;
} CURSOR;

int main()
{
    CURSOR VH;
    CLIST head;

    init(&VH, &head);

    insertLast(&VH, &head, 69);

    return 0;
}

void init(CURSOR* V, CLIST* h)
{
    int x;
    V->avail = 0;
   
    for(x = V->avail; x < MAX-1; x++) {
        V->elements[x].next = x + 1;
    }

    V->elements[x].next = -1;

    *h = -1;
}

void insertLast(CURSOR* VH, CLIST* h, int elem)
{
    if(VH->avail != -1){
        int x = VH->avail;

        VH->avail = VH->elements[x].next;
        VH->elements[x].num = elem;
        VH->elements[x].next = -1;

        if(*h == -1){
            *h = x;
        } else {
            int trav;

            for(trav = *h; VH->elements[trav].next != -1; trav = VH->elements[trav].next) {}
            VH->elements[trav].next = x;
        }
    }
}

//hello i am jethro