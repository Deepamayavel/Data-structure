import random

def kth_smallest(arr, k):
    if not 1 <= k <= len(arr):
        raise ValueError("k is out of bounds")

    def quickselect(arr, k):
        pivot = random.choice(arr)
        left = [x for x in arr if x < pivot]
        mid = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]

        if k <= len(left):
            return quickselect(left, k)
        elif k <= len(left) + len(mid):
            return pivot
        else:
            return quickselect(right, k - len(left) - len(mid))

    return quickselect(arr, k)

try:
    user_input = input("Enter the array elements : ")
    arr = list(map(int, user_input.strip().split()))

    k = int(input(f"Enter the value of k (1 to {len(arr)}): "))

    if k < 1 or k > len(arr):
        print("Error: k must be between 1 and the size of the array.")
    else:
        result = kth_smallest(arr, k)
        print(f"The {k}th smallest element is: {result}")

except ValueError as ve:
    print("Invalid input:", ve)
