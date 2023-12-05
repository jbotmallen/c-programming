#include "header2.h"

int main()
{
	int arr[MAX] = {
		7, 2, 4, 1, 5, 12, 13, 21, 1, 8
	};
	POT tree;
	
	initialize(&tree);
	
	populate(&tree, arr);
	display(tree);
	
	heapify(&tree);
	
	return 0;
}
