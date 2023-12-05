#include<stdio.h>
#include<stdlib.h>
#define MAX 24

typedef struct {
    char FN[24];
	char MI;
	char LN[16];
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
void writeFile();

int main()
{
    readFile();

    system("pause");
    system("cls");

    writeFile();

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
    printf("%-10d%-16s%-24s%-3c%-8s%5d\n", 
        S.ID, S.name.LN, S.name.FN, S.name.MI, S.course, S.yrLevel
    );
}

void readFile()
{
    FILE* fp;
    char fileName[20];
    StudType students;
    int ctr = 1;

    printf("Enter a file name : ");
    scanf("%[^\n]s", fileName);

    fp = fopen(fileName, "rb+");

    displayHeader();

    if(fp != NULL) {
        while(fread(&students, sizeof(StudType), 1, fp) != 0) {
            displayStudent(students);
            if(ctr % 20 == 0) system("pause");
			ctr++;
        }

        fclose(fp);
    }
}

void writeFile()
{
    FILE *fp;

    StudType student[5];

    char fileName[20];
    printf("ENTER THE FILE NAME : ");
    scanf("%s", fileName);
    fp = fopen(fileName, "ab");

    if(fp != NULL) {
        int i;

        for(i = 0; i < 5; i++) {
            printf("ENTER STUDENT LAST NAME: ");
            scanf("%s", student[i].name.LN);
            printf("ENTER STUDENT FIRST NAME: ");
            scanf("%s", student[i].name.FN);
            printf("ENTER STUDENT MIDDLE INITIAL: ");
            scanf(" %c", &student[i].name.MI);
            printf("ENTER STUDENT ID: ");
            scanf(" %d", &student[i].ID);
            printf("ENTER STUDENT YEAR LEVEL: ");
            scanf(" %d", &student[i].yrLevel);
            printf("ENTER STUDENT COURSE: ");
            scanf(" %s", student[i].course);

            fwrite(&student[i], sizeof(StudType), 1, fp);
        }

        fclose(fp);
    }
}

