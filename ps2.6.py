arr = list(map(int, input("Enter array elements:").split()))
key = int(input("Enter key: "))
n = len(arr)
key = key % n
rotated = arr[key:] + arr[:key]
print("Rotated array:", rotated)
