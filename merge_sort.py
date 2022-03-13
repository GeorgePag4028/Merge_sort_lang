def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()

def mergeSort(array):
    if len(array) == 1:
        return array

    mid = len(array)//2
    left_array = mergeSort(array[:mid])
    right_array = mergeSort(array[mid:])
    i = j = k = 0
    n1 = len(left_array)
    n2 = len(right_array)
    while i<n1 and j < n2:
        if left_array[i] < right_array[j]:
            array[k] = left_array[i]
            i+=1
        else :
            array[k] = right_array[j]
            j+=1
        k+=1
    while i< n1 :
        array[k] = left_array[i]
        i+=1
        k+=1


    while j< n2 :
        array[k] = right_array[j]
        j+=1
        k+=1

    return array

if __name__ == '__main__':
    array = [12, 11, 13, 5, 6, 7]
    print("Given array is", end="\n")
    printList(array)
    mergeSort(array)
    print("Sorted array is: ", end="\n")
    printList(array)
