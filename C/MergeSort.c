#include <stdio.h>
#include <math.h>
#include <limits.h>

void MergeSort(int array[], int p, int r);
void merge(int array[], int p, int q, int r);

int main()
{
    int test[] = {18, 25, 6, 9, 15, 12, 5, 20, 11, 30};

    int size = sizeof(test) / sizeof(int);

    printf("\nOriginal array: ");
    for(int i = 0; i < size; i++)
    {
        printf("[%d], ", test[i]);
    }

    printf("\n");
    MergeSort(test, 0, size - 1);

    printf("\nSorted array: ");
    for(int j = 0; j < size; j++)
    {
        printf("[%d], ", test[j]);
    }
    
    printf("\n");

    printf("\nExpected array: [5], [6], [9], [11], [12], [15], [18], [20], [25], [30],\n");

    return 0;
}

/**
 * Recursive mathod to divide-and-conquer and sort an array
 * Recursively sorts the left first
 * And then, recursively sorts the right
*/
void MergeSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = (int) floor((p + r) / 2);
        MergeSort(array, p, q);
	    MergeSort(array, q + 1, r);
	    merge(array, p, q, r);
    }
}

/**
 * Once two halves are sorted, [left and right]
 * This method merges the values from smallest to largest
*/
void merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int leftArray[n1 + 1];
    int rightArray[n2 + 1];

    for(int i = 0; i < n1; i++) { leftArray[i] = array[p + i]; }
    leftArray[n1] = INT_MAX;

    for(int j = 0; j < n2; j++) { rightArray[j] = array[q + j + 1]; }
    rightArray[n2] = INT_MAX;
    
    int i = 0, j = 0;

    for(int k = p; k <= r; k++)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
    }
    
}