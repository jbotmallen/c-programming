#include<stdio.h>
#include<stdlib.h>

void initializeMatrixV1(int M[][5])
{
	int row, col;
	
	for(row = 0; row < 5; row++) {
		for(col = 0; col < 5; col++) {
			M[row][col] = -1;
		}
	}
}

void displayMatrix(int M[][5])
{
	int row, col;
	
	printf("ELEMENTS IN THE MATRIX ARE: \n ------------------------ \n");
	
	for(row = 0; row < 5; row++) {
		printf("|");
		for(col = 0; col < 5; col++) {
			printf(" %2d |", M[row][col]);
		}
		printf("\n");
	}
	printf(" ------------------------ \n");
}

void displayTable(int **M)
{
	int row, col;
	
	printf("ELEMENTS IN THE TABLE ARE: \n ------------------------ \n");
	
	for(row = 0; row < 5; row++) {
		printf("|");
		for(col = 0; col < 5; col++) {
			printf(" %2d |", M[row][col]);
		}
		printf("\n");
	}
	printf(" ------------------------ \n");
}

int** initializeMatrixV2()
{
   int** temp = (int**) malloc(sizeof(int*) * 5);
   int i;
   
   for(i = 0; i < 5; i++) {
       temp[i] = (int*) malloc(sizeof(int) * 5);
   }
   int row, col;
   
   for(row = 0; row < 5; row++) {
       for(col = 0; col < 5; col++) {
           temp[row][col] = -1;
       }
   }
   
   return temp;
}

int main()
{
	int matrix[5][5], **table;
	
	initializeMatrixV1(matrix);
	table = initializeMatrixV2();
	displayMatrix(matrix);
	displayTable(table);
	
	return 0;
}
