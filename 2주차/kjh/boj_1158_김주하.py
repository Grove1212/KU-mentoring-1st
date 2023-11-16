from collections import deque
N, K = map(int, input().split())

que=deque([i for i in range(1,N+1)])

print("<",end='')

while(True):
    for i in range(K-1):
        que.append(que.popleft())
    print(que.popleft(),end='')

    if not que: #queue가 비어있다면
        break
    else:
        print(", ",end="")
print(">")
    
