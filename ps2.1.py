n = int(input("Enter no of elements:"))
arr = []
for i in range(n):
    num = int(input(f"Enter element {i+1}: "))
    arr.append(num)
    arr = list(set(arr))
    arr.sort()
if len(arr)<2:
    print("second largest no doesn't exist")
else:
    print("Second largest value is:", arr[-2])
