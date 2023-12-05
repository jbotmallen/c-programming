#include "header.h"

int binarySearch(int arr[], int value)
{
	int retval, high, low, mid;
	
	for(high = MAX-1, low = 0, mid = (high + low)/2; low <= high; mid = (high + low)/2) {
		printf("| V = %02d | H = %02d | L = %02d | M = %02d |\n",
			value, high, low, mid);
		if(value == arr[mid]) break;
		if(value < arr[mid]) high = mid-1;
		if(value > arr[mid]) low = mid+1;
	}
	
	return retval = (low > high) ? -1 : mid;
}

int getValue()
{
	int retval;
	
	printf("ENTER A VALUE YOU WANT TO FIND: ");
	scanf("%d", &retval);
	
	return retval;
}

void checkSearch(int searched)
{
	searched != -1 ?
	printf("THE VALUE IS FOUND AT INDEX %02d!\n\n", searched) :
	printf("VALUE IS NOT IN THE ARRAY!\n\n");
}
