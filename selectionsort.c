/* -------------------------------------------------------------------------- */
/*                        P.4 Iterative Selection Sort                        */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SWAP(x, y) int t; ((t) = (x), (x) = (y), (y) = (t))

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(int *arr, int size)
{
    for(int i = 0; i < size; i++) {
        int min_idx = i;
        for(int j = i + 1; j < size; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
        
        // option1
        // int tmp = arr[i];
        // arr[i] = arr[min_idx];
        // arr[min_idx] = tmp;
        
        // option2
        // SWAP(arr[i], arr[min_idx]);

        // option3
        swap(&arr[i], &arr[min_idx]);
    }
}

void printArr(int *arr, bool isSorted)
{
    if(isSorted)
        printf("unsorted: ");
    else
        printf("sorted: ");

    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(int argc, char **argv)
{
	int arr[10];

    for(int i = 0; i < 10; i++)
        arr[i] = rand() % 50;
    printArr(arr, false);

    sort(arr, 10);
    printArr(arr, true);

	return 0;
}