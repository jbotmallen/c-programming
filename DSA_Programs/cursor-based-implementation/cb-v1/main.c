#include<stdio.h>
#include<stdlib.h>
#include"declaration.h"
#include"functions.c"

int main()
{
	LIST list;
	CLIST head = -1; 
	
	//INITIALIZATION
	check(initList(&list));
	
	//INSERTS
	check(insertLast(&list, &head, createStudentEntry(createStudentName("ETHAN", "MONTERA", 'D'),
							   createBirthDate(1, 12, 2003), createStudInfo("BS CS", "DCISM", 1.44, 2),
							   "NON-BLOCK", 21600092)));

	check(insertFirst(&list, &head, createStudentEntry(createStudentName("MATTHEW ETHAN", "ISRAEL", 'C'),
							   createBirthDate(1, 8, 2003), createStudInfo("BS IT", "DCISM", 1.89, 2),
							   "BLOCK", 20101265)));
	
	check(insertLast(&list, &head, createStudentEntry(createStudentName("MARK ALLEN", "JUGALBOT", 'P'),
							   createBirthDate(16, 4, 2002), createStudInfo("BS CS", "DCISM", 1.65, 2),
							   "NON-BLOCK", 19104099)));

	check(insertSortedByLastName(&list, &head, createStudentEntry(createStudentName("JETHRO", "JENGUTAN", 'A'),
											createBirthDate(13, 9, 2004), createStudInfo("BS IT", "DCISM", 1.69, 2),
											"NON-BLOCK", 22105047)));

	check(insertSortedByLastName(&list, &head, createStudentEntry(createStudentName("JETHRO", "HENGUTAN", 'A'),
											createBirthDate(13, 9, 2004), createStudInfo("BS IT", "DCISM", 1.69, 2),
											"NON-BLOCK", 22105047)));

	//PRINTING
	displayList(list, head);

	//DELETE FIRST
	check(deleteFirst(&list, &head));
	check(deleteLast(&list, &head));
	check(deleteFirstOccurence(&list, &head, 22105047));

	//PRINTING
	displayList(list, head);

	return 0;
}