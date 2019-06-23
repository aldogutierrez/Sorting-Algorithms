#include <stdio.h>

/**
 * Comparison-based sorting algorithm
 * Runs in O(n^2) time
*/
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int previous = i - 1;
        while (previous >= 0 && array[previous] > key)
        {
            array[previous + 1] = array[previous];
            previous--;
        }
        array[previous + 1] = key;
    }
}

/**
 * Method that prints the passed-in array
 * in the parameter
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
    printf("Given array: ");
    int toBeSorted[] = {15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23};
    int n = sizeof(toBeSorted) / sizeof(int);
    printArray(toBeSorted, n);
    printf("\n");

    insertionSort(toBeSorted, n);

    printf("Sorted array: ");
    printArray(toBeSorted, n);
    printf("\n");
    return 0;
}
