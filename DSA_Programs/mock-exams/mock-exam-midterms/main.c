#include<stdio.h>
#include<stdlib.h>
#include"declaration.h"
#include"functions.c"

int main()
{
    Level L;

    initializeLevel(&L);

    Section group1 = initializeSection(), group2, group3;
    insertSection(&group1, createStudent(createName("MARK ALLEN", "JUGALBOT", "PILAPIL"), createBirthDate(16, "APRIL", 2002),
                    createCourseAndYear("CS", "BS", 2), 1.59, 19104099));
    insertSection(&group1, createStudent(createName("MARK ALLEN", "JUGALBOT", "PILAPIL"), createBirthDate(16, "APRIL", 2002),
                    createCourseAndYear("CS", "BS", 2), 1.59, 19104099));
    insertSection(&group1, createStudent(createName("JETHRO", "ENGUTAN", "ANAGAS"), createBirthDate(14, "SEPTEMBER", 2003),
                    createCourseAndYear("IT", "BS", 2), 1.59, 22105047));

    push(&L, group1);
    displayGroups(&L);

    return 0;
}