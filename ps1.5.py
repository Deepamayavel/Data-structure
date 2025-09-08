s = input("Enter first string:")
t = input("Enter second string:")
if len(s) != len(t):
    print("false")
else:
    if sorted(s) == sorted(t):
        print("true")
    else:
        print("false")
