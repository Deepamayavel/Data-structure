pattern = input("Enter pattern:")
s = input("Enter string:")

words = s.split()
if len(pattern) != len(words):
    print("false")
else:
    mapPT = {}
    mapTP = {}
    follows_pattern = True
    for ch,word in zip(pattern,words):
        if ch in mapPT and mapPT[ch]!= word:
            follows_pattern = False
            break
        if word in mapTP and mapTP[word]!= ch:
            follows_pattern = False
            break
        mapPT[ch]=word
        mapTP[word]=ch
    if follows_pattern:
        print("true")
    else:
        print("false")
