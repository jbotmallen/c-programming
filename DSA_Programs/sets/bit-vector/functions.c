#include <stdio.h>
#include "declaration.h"

void initialize(SET* A)
{
    *A = 0;
}

void insert(SET* A, int idx)
{
    int numOfBits = sizeof(SET) * 8;

    if(*A != 255 && idx < numOfBits) {
        SET mask = 1<<idx;
        *A |= mask;
    }
}

void delete(SET* A, int idx)
{
    int numOfBits = sizeof(SET) * 8;

    if (idx >= 0 && idx < numOfBits) {
        SET mask = ~(1 << idx);
        *A &= mask;
    }
}

int member(SET A, int idx)
{
    SET mask = 1<<(idx);
    return ((A & mask) != 0) ? 1 : 0;
}

SET UNION(SET A, SET B) 
{
    SET C;
    
    C = (A | B);

    return C;
}

SET INTERSECTION(SET A, SET B)
{
    SET C;

    initialize(&C);
    C = (A & B);

    return C;
}

SET DIFFERENCE(SET A, SET B)
{
    int numOfBits = sizeof(SET) * 8, x;
    SET C, mask;

    initialize(&C);
    for(x = numOfBits-1, mask = 1<<(numOfBits-1); mask != 0; mask >>= 1, x--) {
        if(((A & mask) != 0) && ((B & mask) == 0)) {
            insert(&C, x);
        }
    }

    return C;
}

void displayBitPattern(SET A)
{
    if(A != 0) {
        int numOfBits = sizeof(SET) * 8, x;
        SET mask;

        for(mask = 1<<(numOfBits-1), x = 0; mask != 0; mask >>= 1, x++) {
            printf("%d", ((A & mask) != 0) ? 1 : 0);

            if((x + 1) % 4 == 0) 
            printf(" ");
        }

        printf("\n");
    }
}

void displaySet(SET A)
{
    if(A != 0) {
        int numOfBits = sizeof(SET) * 8, x;
        SET mask;

        printf("Elements of the list are : \n");
        for(x = numOfBits-1, mask = 1<<(numOfBits-1); mask != 0; mask >>= 1, x--) {
            if((A & mask) != 0) printf("| %d ", x);
        }
        printf("|\n");
    }
}
