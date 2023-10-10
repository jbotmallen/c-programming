#include <stdio.h>
#include <stdlib.h>
#define MAX 11

int binarySearch(int arr[], int elem, int high, int low)
{
    int mid = high + low / 2;

    if(low > high) {
        return 0;
    } else {
        if(arr[mid] == elem) {
            return 1;
        } else {
            (arr[mid] < elem) ? binarySearch(arr, elem, mid-1, low) : binarySearch(arr, elem, high, mid+1);
        }
    }

    return 1;
}

int main()
{
    int arr[MAX] = { 5, 10, 12, 13, 17, 21, 25, 27, 29, 35, 39};

    binarySearch(arr, 11, MAX-1, 0) ? printf("ELEMENT IS IN THE ARRAY!\n") : printf("ELEMENT IS NOT FOUND IN THE ARRAY");

    return 0;
}