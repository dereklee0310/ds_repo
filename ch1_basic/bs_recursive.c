/* -------------------------------------------------------------------------- */
/*                        P.12 Recursive binary search                        */
/* -------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/249392/binary-search-in-array

// reference: https://stackoverflow.com/questions/27284185/how-does-the-compare-function-in-qsort-work
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int bs(int *arr, int target, int l, int r)
{   
    if(l > r)
        return -1;

    int mid = (l + r) / 2;

    if(arr[mid] == target)
        return mid;
    if(arr[mid] > target)
        return bs(arr, target, l, mid - 1);
    else
        return bs(arr, target, mid + 1, r);
}

void printArr(int *arr)
{
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(int argc, char **argv) {
	int arr[10];

    for(int i = 0; i < 10; i++)
        arr[i] = rand() % 50;
    qsort(arr, 10, sizeof(int), cmpfunc);
    printArr(arr);

    printf("position of 34: %d", bs(arr, 34, 0, 10));


	return 0;
}