#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_MATRIX 5

typedef int** MATRIX;

void populateMatrix(MATRIX M);
void initializeDistList(int* D, int arr[], int source);
MATRIX initializeMatrix();
void displayMatrix(MATRIX M);
int* dijkstraAlgo(MATRIX M, int source);
void initializeSV(int S[], int V[]);
void displayDijkstra(int D[], int source);

#endif
