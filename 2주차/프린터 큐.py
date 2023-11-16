num = int(input())
for i in range(num):
    N, M = map(int,input().split())
    imp = list(map(int,input().split()))
    count = 0
    while imp:
        best = max(imp)
        front = imp.pop(0)
        M -= 1
        if best == front:
            count += 1
            if M<0:
                print(count)
                break
        else:
            imp.append(front)
            if M<0:
                M = len(imp) - 1
