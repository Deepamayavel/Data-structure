def sort012(arr, n):
    low, mid, high = 0, 0, n - 1
    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else: 
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1
n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter array elements (0, 1, 2 only): ").split()))
sort012(arr, n)
print("Sorted array:", *arr)
