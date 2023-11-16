K = int(input())
A = []
stack = []
for i in range(K):
    num = int(input())
    A.append(num)
for j in A:
    if j == 0:
        if stack == []:
            continue
        else:
            stack.pop()
    else:
        stack.append(j)
print(sum(stack))