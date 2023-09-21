#ifndef DECLARATION_H
#define DECLARATION_H

#include<stdio.h>
#include<stdlib.h>
#define MAX 8

//DATA TYPE VARIABLES
typedef unsigned char SET;

//FUNCTIONS
void initialize(SET* A);
void insert(SET* A, int idx);
void delete(SET* A, int idx);
SET UNION(SET A, SET B);
SET INTERSECTION(SET A, SET B);
SET DIFFERENCE(SET A, SET B);
void displayBitPattern(SET A);
void displaySet(SET A);
int member(SET A, int idx);

#endif