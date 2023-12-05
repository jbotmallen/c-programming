#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>

#define MAX_MATRIX 5

typedef int Matrix[MAX_MATRIX][MAX_MATRIX];
typedef int Set[MAX_MATRIX];

void initialize(Matrix M);
void display(Matrix M);
void populateMatrix(Matrix M);

#endif
