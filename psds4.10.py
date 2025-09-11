str=input("enter a string : ")
width=int(input("enter the width : "))
i=0
while i<len(str):
    for j in range(width):
        if i+j<len(str):
            print(str[i+j],end="")
    print()
    i+=width
