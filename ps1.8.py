s ="IceCreAm"
vowels = "aeiouAEIOU"
vowel_list = [ch for ch in s if ch in vowels]
vowel_list.reverse()
result = []
index = 0
for ch in s:
    if ch in vowels:
        result.append(vowel_list[index])
        index += 1
    else:
        result.append(ch)
output = "".join(result)
print("Output:", output)
