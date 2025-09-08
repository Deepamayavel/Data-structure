s = input("Enter a string:")
s = s.lower()
clear = ""
for ch in s:
    if ch.isalnum():
        clear += ch
if clear == clear[::-1]:
    print("true")
else:
    print("false")
