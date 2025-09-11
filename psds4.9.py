text=input("enter a string : ")
cleaned=""
in_space=False
for ch in text:
    if ch==' ':
        if not in_space:
            cleaned+=' '
            in_space=True
    else:
        cleaned+=ch
        in_space=False
print("cleaned string")
print(cleaned)

