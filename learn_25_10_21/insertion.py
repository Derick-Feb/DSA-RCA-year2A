
array = [5, 32, 2, 9, 1, 23, 45, 50, 5, 6, 3, 4, 10, 5, 12, 16, 11, 18, 20, 12, 6, 17]

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

print("Original array:", array)
sorted_array = insertion_sort(array)
print("Sorted array:", sorted_array)