def remove_b_ac(s):
    result=[]
    i=0
    while i<len(s):
        if s[i] == 'b':
            i+=1
        elif i+1<len(s)and s[i]=='a'and s[i+1]=='c':
            i+=2
        else:
            result.append(s[i])
            i+=1
    return "".join(result)
s=input("enter a string:")
print("Result:", remove_b_ac(s))
