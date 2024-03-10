#include "header.h"

void populateMatrix(int** M) {	
	int i, j;
	
	for(i = 0; i < MAX_MATRIX; i++) {
		for(j = 0; j < MAX_MATRIX; j++) {
			M[i][j] = INT_MAX; 
		}
	}
	
	M[0][1] = 2;
	M[0][2] = 5;
	M[1][3] = 4;
	M[2][1] = 1;
	M[2][3] = 3;
	M[2][4] = 2;
	M[4][3] = 5;
}

void initializeDistList(int* D, int arr[], int source) {
	int i;
	
	for(i = 0; i < MAX_MATRIX; i++) {
		D[i] = arr[i];
	}
	
	D[source] = 0;
} 

int** initializeMatrix() {
	int** temp = (int**) malloc(sizeof(int*) * MAX_MATRIX), i;

	for(i = 0; i < MAX_MATRIX; i++) {
		temp[i] = (int*) malloc(sizeof(int) * MAX_MATRIX);
	}
	
	populateMatrix(temp);
	
	return temp;
}

void displayMatrix(int** M) {
	int i, j;
	
	printf("CONTENTS OF THE ADJACANCY MATRIX: \n");
	for(i = 0; i < MAX_MATRIX; i++) {
		printf("-------------------------------------------------------\n");
		for(j = 0; j < MAX_MATRIX; j++) {
			printf("| %d ", M[i][j]);
			if(j + 1 == MAX_MATRIX) printf("|\n");
		}
	}
	printf("-------------------------------------------------------\n");
}

void initializeSV(int S[], int V[]) {
	int i;
	
	for(i = 0; i < MAX_MATRIX; i++) {
		S[i] = 0;
		V[i] = i;
	}
} 

int findMin(int V[], int S[], int* D, int source) {
	int i, ret, min = INT_MAX;
	
	for(i = 0; i < MAX_MATRIX; i++) {
		if(S[i] == 0 && D[i] <= min) {
			min = D[i];
			ret = i;
 		}
	}
	S[ret] = 1;
	
	return ret;
}

void displayDijkstra(int D[], int source) {
	int i;
	
	printf("THE SHORTEST PATH FROM THE SOURCE %d ARE: \n", source);
	for(i = source + 1; i != source; i = (i+1) % MAX_MATRIX) {
		printf("Vertex %d: %d", i, D[i]);
		if((i+1) % MAX_MATRIX != source) printf(" -> ");
	}
	printf("\n");
}

int* dijkstraAlgo(MATRIX M, int source) {
	int* D = (int*) malloc(sizeof(int) * MAX_MATRIX);
	int S[MAX_MATRIX], V[MAX_MATRIX], i, j;
	
	initializeSV(S, V);
	initializeDistList(D, M[source], source);
	
	for(i = source+1; i != source; i = (i+1) % MAX_MATRIX) {
		int minVert = findMin(V, S, D, source);
		
		for(j = 0; j < MAX_MATRIX; j++) {
			if(S[j] == 0 && M[minVert][j] && D[j] != INT_MAX && 
			D[minVert]+M[minVert][j] < D[j]) {
				D[j] = D[minVert] + M[minVert][j];
			} 
		}
	}
	
	return D;
}
