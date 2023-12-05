#include "header.h"

int main()
{
	int arr[MAX] = {
		2, 4, 5, 8, 10, 11, 15, 20, 22, 25, 26, 30
	};
	int value = getValue();
	int search = binarySearch(arr, value);
	checkSearch(search);
	
	return 0;
}
