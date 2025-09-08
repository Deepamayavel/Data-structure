str1=input("enter the 1st string:").replace(" ","").lower()
str2=input("enter the 2nd string:").replace(" ","").lower()
if sorted(str1)==sorted(str2):
    print("the given strings are anagram.")
else:
    print("the given strings are not anagram.")
