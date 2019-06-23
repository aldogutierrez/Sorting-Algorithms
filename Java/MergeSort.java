import java.util.Arrays;

public class MergeSort
{
	/**
	 * Non args ctor for objects of type MergeSort
	 */
	public MergeSort()
	{}

	/**
	 * Sorts the array passed in the argunent in the divide-and-conquer approach known as Merge Sort
	 * @param array
	 */
	public void mergeSort(int array[])
	{
		mergeSort(array, 0, array.length - 1);
	}

	/**
	 * Assistant method to help sort arrays via Merge Sort
	 * @param array
	 * @param p - first index of the array
	 * @param q - middle index of the array
	 * @param r - last index of the array
	 */
	public void merge(int[] array, int p, int q, int r)
	{
		final int n1 = q - p + 1; 	//Denotes the size of the left array
		final int n2 = r - q; 		//Denotes the size of the right array

		int leftArray[] = new int[n1 + 1];
		int rightArray[] = new int[n2 + 1];

		for (int i = 0; i < n1; i++) { leftArray[i] = array[p + i]; }
		leftArray[n1] = Integer.MAX_VALUE; //SENTINEL

		for (int j = 0; j < n2; j++) { rightArray[j] = array[q + j + 1]; }
		rightArray[n2] = Integer.MAX_VALUE; //SENTINEL

		int i = 0, j = 0;

		for (int k = p; k <= r; k++)
		{
			if (leftArray[i] <= rightArray[j])
			{
				array[k] = leftArray[i++];
			}
			else
			{
				array[k] = rightArray[j++];
			}
		}
	}

	/**
	 * Recursive method that divides the arrays into halves and sorts them
	 * @param array
	 * @param p - first index of the array
	 * @param r - last index of the array
	 */
	public void mergeSort(int array[], int p, int r)
	{
		if (p < r)
		{
			int q = (int) (Math.floor((p + r) / 2));		//q - middle index of the array
			mergeSort(array, p, q);							//Recursively divides the left half
			mergeSort(array, q + 1, r);						//Recursively divides the right half
			merge(array, p, q, r);							//Sorts and merges left & halves
		}
	}

	public static void main(String[] args)
	{
		System.out.println("START");
		int toBeSorted[] = {18, 25, 6, 9, 15, 12, 5, 20, 11, 30};

		System.out.println("Initial array: " + Arrays.toString(toBeSorted));

		System.out.println();

		MergeSort test = new MergeSort();

		test.mergeSort(toBeSorted);

		System.out.println("Sorted array: " + Arrays.toString(toBeSorted));

		System.out.println("END");
	}
}
