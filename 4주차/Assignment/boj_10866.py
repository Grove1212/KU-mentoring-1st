import sys
from collections import deque

s=int(sys.stdin.readline())
de=deque()

for i in range(s):
    arr=sys.stdin.readline().split()
    if arr[0]=='push_front':
        de.appendleft(arr[1])
    elif arr[0]=='push_back':
        de.append(arr[1])
    elif arr[0]=='pop_front':
        if len(de)==0:
            print(-1)
        else:
            print(de.popleft())
    elif arr[0]=='pop_back':
        if len(de)==0:
            print(-1)
        else:
            print(de.pop())
    elif arr[0]=='size':
        print(len(de))
    elif arr[0]=='empty':
        if len(de)==0:
            print(1)
        else:
            print(0)
    elif arr[0]=='front':
        if len(de)==0:
            print(-1)
        else:
            print(de[0])
    else:
        if len(de)==0:
            print(-1)
        else:
            print(de[-1])
