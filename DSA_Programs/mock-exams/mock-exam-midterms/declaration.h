#ifndef DECLARATION_H
#define DECLARATION_H

#include<stdio.h>
#include<string.h>
#define MAXNAME 30
#define MAX 50

typedef char String[MAXNAME];
typedef unsigned char SET;
typedef enum {TRUE, FALSE} Bool;

typedef struct {
    String lastName;
    String firstName;
    String middleName;
} Name;

typedef struct {
    String course;
    String dept;
    int year;
} CourseAndYear;

typedef struct {
    int day;
    int year;
    String month;
} BirthDate;

typedef struct {
    Name studName;
    BirthDate bDay;
    CourseAndYear crsAndYear;
    float gpa;
    int id;
    int next;
} Student;

typedef struct {
    Student studentList[MAX];
    int avail;
    int counter;
    int head;
} Section;

typedef struct level {
    Section group;
    struct level* link;
} *Level;

Name createName(String fName, String lName, String mName);
CourseAndYear createCourseAndYear(String course, String dept, int year);
BirthDate createBirthDate(int day, String month, int year);
Student createStudent(Name studName, BirthDate bDay, CourseAndYear courseAndYear, float gpa, int id);
Section initializeSection();
void initializeLevel(Level* level);
void checkOperation(Bool check);
Bool deallocSpace(Section* S, int index);
int allocSpace(Section* S);

Bool push(Level* L, Section S);
void displayGroups(Level* L);

#endif