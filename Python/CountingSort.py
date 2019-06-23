def countSort(input, output, k):
    counter = [0] * k

    for i in range(0, len(input)):
        counter[input[i]] = counter[input[i]] + 1
    
    for i in range(1, k):
        counter[i] += counter[i - 1]
    
    for j in range(len(input) - 1, -1, -1):
        output[counter[input[j]] - 1] = input[j]
        counter[input[j]] = counter[input[j]] - 1

def getMax(input):
    max = 0
    for i in range(0, len(input)):
        if input[i] > max:
            max = input[i]
    return max + 1

def countingSort(input):
    output = [0] * len(input)
    max = getMax(input)
    countSort(input, output, max)
    return output

# Main function
print("Given array: ")
toBeSorted = [6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 5, 2]
print(toBeSorted)
output = countingSort(toBeSorted)
print("Sorted array: ")
print(output)