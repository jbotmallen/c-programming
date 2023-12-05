#include"header.h"

int main()
{
	//DECLARE AND INITIALIZE TO HAVE LASTIDX OF -1
	Heap pot;
	initialize(&pot);
	
	//POPULATE THE INITIALLY EMPTY P.O.T.
	populate(&pot);
	
	//COMPLETE W/ NO DELETIONS DISPLAY
	printf("BEFORE DELETING: \n");
	display(pot);
	
	//DELETE MINIMUM
	deleteMin(&pot);
	deleteMin(&pot);
	
	//COMPLETE W/ DELETIONS DISPLAY
	printf("AFTER DELETING: \n");
	display(pot);
	
	return 0;
}
