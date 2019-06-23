def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        previous = i - 1

        while previous >= 0 and array[previous] > key:
            array[previous + 1] = array[previous]
            previous -= 1
        
        array[previous + 1] = key

toBeSorted = [15, 4, 8, 26, 32, 27, 51, 72, 78, 21, 2, 8, 23]
print("Current array: ")
print(*toBeSorted, sep = ", ")

insertionSort(toBeSorted)

print("Sorted array: ")
print(*toBeSorted, sep = ", ")