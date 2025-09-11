def is_prime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5+1)):
        if n%i==0:
            return False
    return True
array=input("enter array element : ")
arr = list(map(int,array.replace(',', ' ').split()))
result=[num for num in arr if not is_prime(num)]
print("array element without prime numbers:")
for num in result:
    print(num)

