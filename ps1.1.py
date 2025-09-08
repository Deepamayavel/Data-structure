s = input("Enter a string:")
s = s.strip()
words = s.split(" ")
last_word = words[-1]
print(len(last_word))
