from collections import deque
N, K = map(int, input().split())

que=deque([i for i in range(1,N+1)])
want=list(map(int,input().split()))
#-----------기초 작업 ---------------

count=0
for i in want:
    while(True):
        if(que[0]==i):
            que.popleft()
            break
        else:
            if(que.index(i)<=len(que)/2):
                que.append(que.popleft())
                count+=1
            else:
                que.appendleft(que.pop())
                count+=1
print(count)
