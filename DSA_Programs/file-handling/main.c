#include<stdio.h>
#include<stdlib.h>
#define MAX 24

typedef char String[MAX];
typedef struct {
    String FN, LN;
    char MI;
} Nametype;
typedef struct {
    Nametype name;
    int ID;
    char course[8];
    int yrLevel;
} StudType;

void displayHeader();
void displayStudent(StudType S);
void readFile();

int main()
{
    readFile();

    return 0;
}

void displayHeader()
{
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-24s", "Firstname");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year");
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "====\n");
}

void displayStudent(StudType S)
{
    printf("%-10d %-16s %-24s %-3c %-8s %5d\n", 
        S.ID, S.name.LN, S.name.FN, S.name.MI, S.course, S.yrLevel
    );
}

void readFile()
{
    FILE* fp;
    String fileName;
    StudType students;
    int ctr = 0;

    printf("Enter a file name : ");
    scanf(" %s", fileName);

    fp = fopen(fileName, "rb+");

    displayHeader();

    if(fp != NULL) {
        while(fread(&students, sizeof(StudType), 1, fp) != 0) {
            displayStudent(students);
            (ctr % 20 == 0) ? system("pause") : ctr++;
        }

        fclose(fp);
    }
}