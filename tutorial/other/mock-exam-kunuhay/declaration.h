#ifndef DECLARATION_H
#define DECLARATION_H

#define MAX 50

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char String[MAX];
typedef enum { TRUE, FALSE} Bool;
char line[200] = {"=========================================================================================================================================="};

typedef struct {
    String firstName;
    String lastName;
    String middleName;
} Name;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    String course;
    String dept;
    int year;
} CourseAndYear;

typedef struct {
    Name studName;
    Date bDay;
    Date enrolledAt;
    CourseAndYear crsAndYear;
    float gpa;
    int id;
    char gender;
} Student;

typedef struct {
    Student roster[MAX];
    int count;
} Roster;

//HELPER FUNCTIONS
Name createName(String fn, String ln, String mn);
Date createDate(int day, int month, int year);
CourseAndYear createEntry(String course, String dept, int year);
Student createStudent(Name name, Date bDay, Date enrolledAt, CourseAndYear crsAndYear, float gpa, int id, char gender);
int compare(Date date1, Date date2);

Bool initialize(Roster* R);
Roster populate();
void displayList(Roster R);
Roster getListOfLateEnrollees(Roster R, int month);
Bool addToSortedList(Student stud, Roster* R);
Bool sortedByEnrolledDate(Roster* R);

#endif