tests = int(input())
for _ in range(tests):
    n, q = map(int, input().split(" "))

    blocks = input()

    successes = 0
    for t in range(q):
        l, r = map(int, input().split(" "))
        mslice = blocks[l - 1 : r]
        
        len_mslice = r - l + 1
        l_dic = {}

        for char in mslice:
            if char in l_dic:
                l_dic[char] += 1
            else:
                l_dic[char] = 1

        odds = 0 if len_mslice % 2 == 0 else -1
        failed = False
        for key, val in l_dic.items():
            if val % 2 == 1:
                odds +=1
                if odds > 0:
                    failed = True
                    break
        
        if failed:
            continue

        successes += 1

    print("Case #{}: {}".format(_ + 1, successes))