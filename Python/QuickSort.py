def partition(array, p, r):
    pivot = array[r]
    i = p - 1

    for j in range(p, r):
        if array[j] <= pivot:
            i = i + 1
            array[i], array[j] = array[j], array[i]
    
    array[i + 1], array[r] = array[r], array[i + 1]
    return (i + 1)

def quickSort(array, p, r):
    if p < r:
        q = partition(array, p, r)
        quickSort(array, p, q - 1)
        quickSort(array, q + 1, r)


toBeSorted = [15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23]
print("Given array: ")
print (toBeSorted)

quickSort(toBeSorted, 0, len(toBeSorted) - 1)

print("Sorted array: ")
print (toBeSorted)