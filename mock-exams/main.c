#include "functions.c"

int main()
{
    OrderList L;
    initializeOrderList(&L);

    OrderDic D;
    initializeDicitonary(D);

    populateListFromFile(&L, "chocolates.bin");

    printOrderList(L);
    
    return 0;
}