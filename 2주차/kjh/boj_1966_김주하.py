from collections import deque

#기초 과정
document,want=map(int,input().split())
que=deque(map(int,input().split()))
count=1 #출력 값
val = que[want]

while 1:
    if(que[0]==val and que[0]==max(que)):
        break
    if(que[0]==max(que)):
        que.popleft()
        count+=1
    else:
        que.append(que.popleft())
        
print(count)
