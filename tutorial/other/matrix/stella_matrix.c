#include <stdio.h>
#include <stdlib.h>
/**
    Check out how to add and multiply 2 matrices here:
    https://tinyurl.com/y3t5xah2
*/

int** matrixAddition(int A[][3], int B[][3]);
int** matrixMultiplication(int A[][3], int B[][3]);
void display(int **C) {
    int i, j;
    for(i = 0; i < 3; i++) {
        printf("\t");
        for(j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[3][3] = {
        {1,3,6},
        {7,4,9},
        {6,3,6}
    };
    
    int B[3][3] = {
        {6,5,1},
        {2,0,8},
        {7,3,2}
    };
    
    int** add = matrixAddition(A, B);
    int** mult = matrixMultiplication(A, B); 
    
    
    return 0;
}

int** matrixAddition(int A[][3], int B[][3])
{
    int** C = (int**) malloc(sizeof(int*) * 3);
    int x;
    
    for(x = 0; x < 3; x++) {
    	C[x] = (int*) malloc(sizeof(int) * 3);
	}
    int i, j;
    /**
        Implement matrix addition here
    */
    
    for(i = 0; i < 3; i ++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    printf("\nMatrix Addition: \n");
    display(C);
    
    /*
    7  8  7
    9  4  17
    13 6  8
    */
    
    return C;
}

int** matrixMultiplication(int A[][3], int B[][3]) 
{
    /**
        Implement matrix multiplication here.
    */
    int** C = (int**) malloc(sizeof(int*) * 3);
    int x;
    
    for(x = 0; x < 3; x++) {
    	C[x] = (int*) malloc(sizeof(int) * 3);
	}
    int i, j, k;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            int sum = 0;
            for(k = 0; k < 3; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    
    printf("\nMatrix Multiplication: \n");
    display(C);
}
