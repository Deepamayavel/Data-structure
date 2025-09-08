arr = list(map(int,input("Enter numbers: ").split()))
x = int(input("Enter the number to search: "))
if x in arr:
    pos = arr.index(x)
    print("position:",pos)
else:
    print("Number not found in the array.")
