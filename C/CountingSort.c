#include <stdio.h>
#include <stdlib.h>

int findMax(int *array, int size);
void countingSort(int *input, int *output, int k, int size);
void printArray(int *array, int size);

/**
 * Linear sorting for integer values
*/
void countingSort(int *input, int *output, int k, int size)
{
    int *counter = (int *) malloc(sizeof(int) * (k));
    int i;

    for (i = 0; i < k; i++) { counter[i] = 0; }
    
    for (i = 0; i < size; i++) { counter[input[i]]++; }

    for (i = 1; i < k; i++) { counter[i] += counter[i - 1]; }
    
    for (i = (size - 1); i >= 0; --i)
    {
        output[counter[input[i]] - 1] = input[i];
        counter[input[i]]--;
    }
    return;
}

/**
 * Returns the maximum entry in the array
 * The reason why we return 1 more than the max is to
 * satisfy the "arrays start at zero" rule
*/
int findMax(int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max) { max = array[i]; }
    }
    return ++max;
}

/**
 * Prints the given array
*/
void printArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d, ", array[i]);
    }
}

int main()
{
    printf("***START***\n\n");
    
    // int toBeSorted[] = {4, 2, 0, 1, 3, 7, 6, 1, 3, 2};
    int toBeSorted[] = {15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23};
    
    int size = (sizeof(toBeSorted) / sizeof(int));
    
    // Preallocate the output array
    int *output = (int *)malloc(sizeof(int) * (size));

    printf("Given array: ");
    printArray(toBeSorted, size);

    printf("\n");

    int maxValue = findMax(toBeSorted, size);
    countingSort(toBeSorted, output, maxValue, size);

    printf("Sorted array: ");

    printArray(output, size);

    printf("\n\n***END***");
    return 0;
}