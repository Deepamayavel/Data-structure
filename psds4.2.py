n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter array elements: ").replace(",", " ").split()))
pos = int(input("Enter position to split: "))
arr = arr[pos:] + arr[:pos]
non_zero = [x for x in arr if x != 0]
zeros = [0] * arr.count(0)
result = non_zero + zeros
print(*result)
