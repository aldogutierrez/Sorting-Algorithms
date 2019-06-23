#include <stdio.h>

int findMax(int *array, int size);
int findMin(int *array, int size);

/**
 * 
*/
int * countingSort(int *input, int k, int size)
{
    int counter[k + 1];
    int output[size];

    for (int i = 0; i <= k; i++)
    {
        counter[i] = 0;
    }

    for (int j = 0; j < size; j++)
    {
        counter[input[j]] = counter[input[j]] + 1;
        output[j] = 0;
    }

    for (int i = 1; i < k; i++)
    {
        counter[i] += counter[i - 1];
    }

    for (int j = size - 1; j >= 0; j--)
    {
        output[counter[input[j]] - 1] = input[j];
        counter[input[j]] -=  1;
    }

    int * result = output;
    return result;
}

/**
 * 
*/
int findMax(int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

/**
 * 
 */
int findMin(int *array, int size)
{
    int min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

/**
 * 
*/
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d], ", array[i]);
    }
}

int main()
{
    printf("***START***\n");
    int toBeSorted[] = {15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23}; //{7, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int size = sizeof(toBeSorted) / sizeof(int);
    
    printf("Given array: ");
    printArray(toBeSorted, size);
    
    printf("\n");
    
    int maxValue = findMax(toBeSorted, size);
    int minValue = findMin(toBeSorted, size);
    int * result = countingSort(toBeSorted, maxValue, size);
    
    result[size - 1] = maxValue;
    result[0] = minValue;


    printf("Sorted array: ");

    printArray(result, size);
    
    printf("\n");
    printf("***END***");
    printf("\n");
    return 0;
}