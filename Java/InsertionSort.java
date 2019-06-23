import java.util.Arrays;

public class InsertionSort
{
    /**
     * 
     * @param array
     */
    public static void insertionSort(int array[])
    {
        for (int i = 1; i < array.length; i++)
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

    public static void main(String[] args)
    {
        int[] toBeSorted = {15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23};
        System.out.println("***START***");
        System.out.println("Given array: " + Arrays.toString(toBeSorted));
        insertionSort(toBeSorted);
        System.out.println("Sorted array: " + Arrays.toString(toBeSorted));
        System.out.println("***END***");
    }
}