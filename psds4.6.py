def rearrange_array(arr):
    positive=[]
    negative=[]
    for num in arr:
        if num>=0:
            positive.append(num)
        else:
            negative.append(num)
    return positive+negative
try:
    user=input("enter the element:")
    arr=list(map(int,user.strip().split()))
    result=rearrange_array(arr)
    print("Result array:",result)
except valueError as ve:
    print("invalid input:",ve)
