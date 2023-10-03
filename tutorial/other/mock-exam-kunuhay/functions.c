#include"declaration.h"

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
    Roster* R;

    R.roster[0] = createStudent(createName("ZENNO", "ABELLANA", "DOMINIQUE"), createDate(31, 12, 2001), createDate(20, 10, 2019), createEntry("BS IT", "DCISM", 2), 1.11, 21104304, 'M');
    R.roster[1] = createStudent(createName("SAMANTHA", "ANTIPORTA", "NICA"), createDate(5, 8, 2004), createDate(8, 11, 2018), createEntry("BS CS", "DCISM", 1), 1.11, 17451918, 'F');
    R.roster[2] = createStudent(createName("JETHRO", "ENGUTAN", "DOTA"), createDate(15, 10, 2003), createDate(3, 8, 2020), createEntry("BS IT", "DCISM", 2), 1.56, 22105047, 'M');
    R.roster[3] = createStudent(createName("MARK ALLEN", "JUGALBOT", "PILAPIL"), createDate(16, 4, 2002), createDate(10, 10, 2019), createEntry("BS CS", "DCISM", 2), 1.56, 19104099, 'M');
    R.roster[4] = createStudent(createName("BELLE", "LASTIMOSA", "BRIDGET"), createDate(4, 5, 2003), createDate(15, 5, 2019), createEntry("BS CS", "DCISM", 2), 1.56, 19104099, 'F');
    R.roster[5] = createStudent(createName("SHEENA STELLA", "SALDE", "AVANCEÑA"), createDate(24, 10, 2004), createDate(11, 12, 2018), createEntry("BS CS", "DCISM", 1), 1.11, 17451918, 'F');

    return &R;
}

void displayList(Roster R)
{
    //IMPLEMENT YOUR DISPLAY HERE
}

Roster getListOfLateEnrollees(Roster R, int month)
{
    //IMPLEMENT YOUR CODE HERE
}

Bool addToSortedList(Student stud, Roster* R)
{
    //IMPLEMENT YOUR FUNCTION HERE
}

Bool sortedByEnrolledDate(Roster* R)
{
    //IMPLEMENT FUNCTION HERE
}
