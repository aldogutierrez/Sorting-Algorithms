#include <stdio.h>

/**
 * Simple method that swaps two
 * elementts in the passed in array
*/
void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
 * Method that partitions an array
 * with a "pivot", the pivot is the last
 * elements in the array in this case
 * -
 * All elements to the left of the pivot
 * are less than or equal to the value
 * of the pivot
 * -
 * All elements to the right of the pivot
 * are greater than the value of the pivot
*/
int partition(int array[], int p, int r)
{
    int pivot = array[r];
    int i = (p - 1);
    
    for (int j = p; j <= r - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, r);
    return (i + 1);
    
}

/**
 * Recursive method that sorts the left recursively
 * and then, sorts the right recursivley
 * -
 * This is an in-place algorithm
*/
void quickSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

/**
 * Method that prints the array in the 
 * passed-in parameter
*/
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d], ", array[i]);
    }
}

int main()
{
    int toBeSorted[] = {12, 8, 6, 4, 75, 64, 17, 46, 24, 76, 15, 20};
    printf("\nGiven array : ");
    int size = sizeof(toBeSorted) / sizeof(int);
    printArray(toBeSorted, size);

    printf("\n");
    quickSort(toBeSorted, 0, size - 1);

    printf("Sorted array : ");
    printArray(toBeSorted, size);
    printf("\n");
    
    return 0;
}