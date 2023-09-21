#include <stdio.h>

void displayBitPattern(int num) {
    int x;

    int numBits = sizeof(int) * 8;
    int mask = 1 << (numBits - 1);

    for (x = 0; x < numBits; x++) {
        int bit = (num & mask) ? 1 : 0;
        printf("%d", bit);

        if ((x + 1) % 4 == 0)
            printf(" ");

        mask >>= 1;
    }

    printf("\n");
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Bit pattern: ");
    displayBitPattern(num);

    return 0;
}
