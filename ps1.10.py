s = "ababbc"
k = 2
stack = [(s,)]
max_len = 0

while stack:
    current = stack.pop()[0]
    if len(current) < k:
        continue
    
    freq = {}
    for ch in current:
        freq[ch] = freq.get(ch, 0) + 1
    
    split_found = False
    for i, ch in enumerate(current):
        if freq[ch] < k:
            stack.append((current[:i],))
            stack.append((current[i+1:],))
            split_found = True
            break
    
    if not split_found:
        max_len = max(max_len, len(current))

print(max_len)
