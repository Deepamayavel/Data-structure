print("count the vowels")
name=input("enter the name:")
vowels=['a','e','i','o','u','A','E','I','O','U']
count=0
for ch in name:
    if ch in vowels:
        count+=1
print("no.of vowels:",count)

print("string operations")
str=input("enter a string:")

length=0
for ch in str:
    length +=1
print(length)

print("".join(str[length-i-1]for i in range(length)))

copied=""
for ch in str:
    copied+=ch
print(copied)
