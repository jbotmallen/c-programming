#include <stdio.h>

int main()
{
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++) {
        printf("  ");
    }
    printf("*\n");
    for (int i = 0; i < size-1; i++)
    {
        for(int k = 0; k < size; k++) {
            if(k == size - i - 1) {
                printf("*");
            }
            printf("  ");
        }
        for (int j = 0; j < size; j++) {
            printf("  ");
            if(j == i)
            printf("*");
        }
        printf("\n");
    }

    for(int i = size-1; i >= 0; i--) {
        for(int j = size; j >= 0; j--) {
            printf("  ");
            if(j == size-i-1) {
                printf("*");
            }
        }
        for(int k = size-1; k >= 0; k--) {
            if(k != i) printf("  ");
            else printf("*");
        }
        printf("\n");
    }

    return 0;
}