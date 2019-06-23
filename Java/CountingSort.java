import java.util.Arrays;

public class CountingSort
{
    public CountingSort() {}

    public static void countingSort(int input[], int output[], int k)
    {
        int counter[] = new int[k];
        for (int i = 0; i < k; i++)
        {
            counter[i] = 0;
        }

        for (int j = 0; j < input.length; j++)
        {
            counter[input[j]] = counter[input[j]] + 1;
        }

        for (int i = 1; i < k; i++)
        {
            counter[i] += counter[i - 1];
        }

        for (int j = input.length - 1; j >= 0; j--)
        {
            output[counter[input[j]] - 1] = input[j];
            counter[input[j]] = counter[input[j]] - 1;
        }
    }

    public static int[] countSort(int array[])
    {
        int output[] = new int[array.length];
        int max = findMax(array);
        countingSort(array, output, max);
        return output;
    }

    public static int findMax(int array[])
    {
        int max = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] > max) {max = array[i];}
        }
        return ++max;
    }

    public static void main(String[] args)
    {
        System.out.println("***START***");
        int toBeSorted[] = {15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23}; //{6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
        int sorted[] = countSort(toBeSorted);
        System.out.println("Given array: " + Arrays.toString(toBeSorted));
        System.out.println("Sorted array: " + Arrays.toString(sorted));
        System.out.println("***END***");
    }
}