from collections import defaultdict

def groupAnagrams(strs):
    groups = defaultdict(list)
    for s in strs:
        key = "".join(sorted(s))
        groups[key].append(s)
    return list(groups.values())

def main():
    n = int(input("Enter number of strings: "))
    strs = []
    print(f"Enter {n} strings:")
    for _ in range(n):
        strs.append(input().strip())
    
    result = groupAnagrams(strs)
    print("Grouped anagrams:")
    print(result)

if __name__ == "__main__":
    main()
