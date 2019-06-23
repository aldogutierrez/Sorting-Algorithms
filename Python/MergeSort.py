def mergeSort(array, p, r):
    if p < r:
        q = (p + r) // 2
        mergeSort(array, p, q)
        mergeSort(array, q + 1, r)
        merge(array, p, q, r)

def merge(array, p, q, r):
    n1 = q - p + 1
    n2 = r - q

    leftArray = [0] * (n1 + 1)
    rightArray = [0] * (n2 + 1)

    for i in range(0, n1):
        leftArray[i] = array[p + i]

    for j in range(0, n2):
        rightArray[j] = array[q + j + 1]
    
    leftArray[n1] = 99999
    rightArray[n2] = 99999

    i = j = 0
    for k in range(p, r + 1):
        if leftArray[i] <= rightArray[j]:
            array[k] = leftArray[i]
            i += 1
        else:
            array[k] = rightArray[j]
            j += 1


toBeSorted = [15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23]
print("Current array: ")
print(*toBeSorted, sep = ", ")

mergeSort(toBeSorted, 0, len(toBeSorted) - 1)

print("Sorted array: ")
print(*toBeSorted, sep = ", ")