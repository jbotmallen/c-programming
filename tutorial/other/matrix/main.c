#include "header.h"

int main()
{
	Matrix table;
	
	initialize(table);
	printf("SUCCESSFULLY INITIALIZED! ");
	display(table);
	system("pause");
	system("cls");
	
	populateMatrix(table);
	printf("SUCCESSFULLY POPULATE MATRIX! ");
	display(table);
	
	return 0;
}

void initialize(Matrix M)
{
	int x, y;
	
	for(x = 0; x < MAX_MATRIX; x++) 
		for(y = 0; y < MAX_MATRIX; y++)
			M[x][y] = 0;
}

void display(Matrix M)
{
	int x, y;
	
	printf("MATRIX ELEMENTS:\n");
	printf(" ----------------------------- \n");
	
	for(x = 0; x < MAX_MATRIX; x++) {
		printf("|"); 
		for(y = 0; y < MAX_MATRIX; y++)
			printf(" %3d |", M[x][y]);
		printf("\n ----------------------------- \n");
	}
}

void populateMatrix(Matrix M)
{
	M[0][1] = 10;
	M[0][4] = 100;
	M[0][3] = 30;
	M[1][2] = 50;
	M[2][0] = 20;
	M[2][4] = 10;
	M[3][2] = 20;
	M[3][4] = 60;
}

void difference(int start, Set A, Set B)
{
	int x;
	
	for(x = start; x < MAX_MATRIX; x++) {
		A[x] = (B[x] == A[x]) ? A[x] : B[x];
	}
} 

void Dijkstra(Matrix M)
{
	int x;
	Set S = { 0 }, V, D;
	
	for(x = 0; x < MAX_MATRIX; x++) {
		D[x] = M[0][x];
		V[x] = x;
	}
		
	for(x = 1; x < MAX_MATRIX; x++) {
		difference(x, S, V);
	}
}
