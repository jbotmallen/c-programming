#include"declaration.h"

char line[200] = {"=========================================================================================================================================="};

//HELPER FUNCTIONS
Name createName(String fn, String ln, String mn)
{
    Name name;
    
    strcpy(name.firstName, fn);
    strcpy(name.lastName, ln);
    strcpy(name.middleName, mn);

    return name;
}

Date createDate(int day, int month, int year)
{
    Date newDate;

    newDate.day = day;
    newDate.month = month;
    newDate.year = year;

    return newDate;
}

CourseAndYear createEntry(String course, String dept, int year)
{
    CourseAndYear entry;

    strcpy(entry.course, course);
    strcpy(entry.dept, dept);
    entry.year = year;

    return entry;
}

Student createStudent(Name name, Date bDay, Date enrolledAt, CourseAndYear crsAndYear, float gpa, int id, char gender)
{
    Student stud;

    stud.studName = name;
    stud.bDay = bDay;
    stud.enrolledAt = enrolledAt;
    stud.crsAndYear = crsAndYear;
    stud.gpa = gpa;
    stud.id = id;
    stud.gender = gender;

    return stud;
}

//NEEDS IMPLEMENTATION
Bool initialize(Roster* R)
{
    Bool ret = FALSE;

    R->count = 0;
    ret = TRUE;

    return ret;
}

Roster populate()
{
    Roster R;
    Bool ret = FALSE;

    R.roster[0] = createStudent(createName("ZENNO", "ABELLANA", "DOMINIQUE"), createDate(31, 12, 2001), createDate(20, 10, 2019), createEntry("BS IT", "DCISM", 2), 1.11, 21104304, 'M');
    R.roster[1] = createStudent(createName("SAMANTHA", "ANTIPORTA", "NICA"), createDate(5, 8, 2004), createDate(8, 11, 2018), createEntry("BS CS", "DCISM", 1), 1.11, 17451918, 'F');
    R.roster[2] = createStudent(createName("JETHRO", "ENGUTAN", "DOTA"), createDate(15, 10, 2003), createDate(3, 8, 2020), createEntry("BS IT", "DCISM", 2), 1.56, 22105047, 'M');
    R.roster[3] = createStudent(createName("MARK ALLEN", "JUGALBOT", "PILAPIL"), createDate(16, 4, 2002), createDate(10, 10, 2019), createEntry("BS CS", "DCISM", 2), 1.56, 19104099, 'M');
    R.roster[4] = createStudent(createName("BELLE", "LASTIMOSA", "BRIDGET"), createDate(4, 5, 2003), createDate(15, 5, 2019), createEntry("BS CS", "DCISM", 2), 1.56, 19104099, 'F');
    R.roster[5] = createStudent(createName("SHEENA STELLA", "SALDE", "AVANCEÑA"), createDate(24, 10, 2004), createDate(11, 12, 2018), createEntry("BS CS", "DCISM", 1), 1.11, 17451918, 'F');

    ret = TRUE;

    R.count = 6;

    return R;
}

void displayList(Roster R)
{
    int x;

    printf("%s\n", line);
    printf("%11s | %20s, %20s %2s | %6s | %5s | %8s | %10s | %10s - %4s | %5s |\n",
    "ID NUMBER", "LAST NAME", "FIRST NAME", "MI.", "GENDER", "BIRTH DATE", "ENROLLEDAT", "DEPT", "COURSE", "YEAR", "GPA");
    printf("%s\n", line);

    for(x = 0; x < R.count; x++) {
        printf("%11d | %20s, %20s %2c. | %6c | %02d/%02d/%04d | %02d/%02d/%04d | %10s | %10s - %4d | %5.2f |\n",
        R.roster[x].id, R.roster[x].studName.lastName, R.roster[x].studName.firstName, R.roster[x].studName.middleName[0],
        R.roster[x].gender, R.roster[x].bDay.day, R.roster[x].bDay.month, R.roster[x].bDay.year, 
        R.roster[x].enrolledAt.day, R.roster[x].enrolledAt.month, R.roster[x].enrolledAt.year,
        R.roster[x].crsAndYear.dept, R.roster[x].crsAndYear.course, R.roster[x].crsAndYear.year, R.roster[x].gpa);
    }
    printf("%s\n", line);
}

Roster getListOfLateEnrollees(Roster R, int month)
{
    Roster temp;
    int x;

    initialize(&temp);

    for(x = 0; x < R.count; x++) {
        if(R.roster[x].enrolledAt.month > month) {
            temp.roster[temp.count++] = R.roster[x];
        }
    }

    return temp;
}

Bool addToSortedList(Student stud, Roster* R)
{
    Bool ret = FALSE;

    if(R->count < MAX) {
        int x;
        for(x = R->count-1; x >= 0 && strcmp(stud.studName.lastName, R->roster[x].studName.lastName) < 0; x--) {
            R->roster[x+1] = R->roster[x];
        }

        R->roster[x+1] = stud;
        R->count++;

        ret = TRUE;
    }

    return ret;
}

int compare(Date date1, Date date2)
{
    if(date1.year > date2.year) {
        return 1;
    }
    if(date1.year == date2.year && date1.month > date2.month) {
        return 1;
    }
    if(date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) {
        return 1;
    }

    return -1;
}

Bool sortedByEnrolledDate(Roster* R)
{
    Bool ret = FALSE;
    int x, y;
    Student temp; 

    for(x = 0; x < R->count - 1; x++) {
        for(y = 0; y < R->count-x-1; y++) {
            if(compare(R->roster[y].enrolledAt, R->roster[y+1].enrolledAt) > 0) {
                temp = R->roster[y];
                R->roster[y] = R->roster[y+1];
                R->roster[y+1] = temp;
            }
        }
    }

    ret = TRUE;

    return ret;
}
