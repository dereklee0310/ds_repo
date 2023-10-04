/* -------------------------------------------------------------------------- */
/*                         P.6 Iterative binary search                        */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// reference: https://stackoverflow.com/questions/27284185/how-does-the-compare-function-in-qsort-work
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int bs(int *arr, int target, int l, int r)
{   
    int mid;

    while(l <= r) {
        mid = (l + r) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    return -1;
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