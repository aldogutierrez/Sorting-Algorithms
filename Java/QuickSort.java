import java.util.Arrays;

public class QuickSort
{
    public QuickSort() {}

    public static void swap(int array[], int a, int b)
    {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
    
    public static int partition(int array[], int p, int r)
    {
        int pivot = array[r];
        int i = p - 1;
        
        for (int j = p; j < r ; j++)
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

    public static void quicksort(int array[], int p, int r)
    {
        if (p < r)
        {
            int q = partition(array, p, r);
            quicksort(array, p, q - 1);
            quicksort(array, q + 1, r);
        }
    }

    public static void quickSort(int array[])
    {
        quicksort(array, 0, array.length - 1);
    }
    public static void main(String[] args)
    {
        int array[] = {3, 6, 1, 5, 8, 2, 4, 7, 3}; //{15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23};

        System.out.println("***START***");
        System.out.println("Given array: " + Arrays.toString(array));
        quickSort(array);
        System.out.println("Sorted array: " + Arrays.toString(array));
        System.out.println("***END***");
    }
}