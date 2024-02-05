from collections import deque

lst=list(input().split())
stack=deque()
for i in lst:
    if(i==' '):
        for i in stack:
            print(i,end='')
        print(' ',end='')
    else:
        stack.appendleft(i)
