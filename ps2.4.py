arr = list(map(int, input("Enter the elements of the array: ").split()))

positive = negative = even = odd = 0

for num in arr:
    if num > 0:
        positive += 1
    elif num < 0:
        negative += 1
    
    if num % 2 == 0:
        even += 1
    else:
        odd += 1

print("Number of positive elements:", positive)
print("Number of negative elements:", negative)
print("Number of even elements:", even)
print("Number of odd elements:", odd)
