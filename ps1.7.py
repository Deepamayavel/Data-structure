words = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Masks = []
Lengths = []
for word in words:
    Mask = 0
    for ch in word:
        Mask|=1<<(ord(ch)-ord('a'))
    Masks.append(Mask)
    Lengths.append(len(word))
max_product = 0
n = len(words)
for i in range(n):
    for j in range(i+1, n):
        if Masks[i] & Masks[j] == 0:
            product = Lengths[i] * Lengths[j]
            max_product = max(max_product, product)
print("Maximum product =", max_product)
