s = input("Enter first string: ")
t = input("Enter second string: ")
if len(s) != len(t):
    print("false")
else:
    mapST = {}
    mapTS = {}
    is_isomorphic = True

    for i in range(len(s)):
        ch_s, ch_t = s[i], t[i]

        if ch_s in mapST and mapST[ch_s] != ch_t:
            is_isomorphic = False
            break
        if ch_t in mapTS and mapTS[ch_t] != ch_s:
            is_isomorphic = False
            break

        mapST[ch_s] = ch_t
        mapTS[ch_t] = ch_s

    if is_isomorphic:
        print("true")
    else:
        print("false")
