num = int(input())

for i in range(num):
    arr = list(input().strip())
    stack = []

    for char in arr:
        if char == '(':
            stack.append('(')
        else:
            if  stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(')')

    if not stack:
        print("YES")
    else:
        print("NO")
