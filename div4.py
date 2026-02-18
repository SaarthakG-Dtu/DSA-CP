t = int(input())
for _ in range(t):
    n = int(input())
    l=list(map(int,input().split()))
    m=min(l)
    if m != 0:
        l = [x - m for x in l]
    for i in range(len(l)+1):
        if i not in l:
            print(i)
            break



t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    mex = 0
    for v in a:
        if v <= mex:
            mex += 1

    print(mex)






















    # for i in range(1, n + 1):
    #     print(i, end=" ")
    # print()
