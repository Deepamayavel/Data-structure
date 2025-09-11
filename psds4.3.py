def findpeakelement(arr,n):
    low,high=0,n-1
    while low<=high:
        mid=(low+high)//2
        if(mid==0 or arr[mid]>=arr[mid-1])and(mid==n-1 or arr[mid]>=arr[mid+1]):
            return mid
        elif mid>0 and arr[mid-1]>arr[mid]:
            high=mid-1
        else:
            low=mid+1
    return -1
n=int(input("enter no.of elements:"))
arr=list(map(int,input("enter array elements:").split()))
index=findpeakelement(arr,n)
print(f"peak element found at index:{index},value:{arr[index]}")
    
