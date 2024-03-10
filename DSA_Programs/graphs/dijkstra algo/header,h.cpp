#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#define MAX_MATRIX 5

typedef int MATRIX[MAX_MATRIX][MAX_MATRIX];

void populateMatrix(int** M);
int** initializeMatrix();

#endif
