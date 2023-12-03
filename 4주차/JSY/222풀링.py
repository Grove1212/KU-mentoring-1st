import sys
import heapq

N = int(input())
A = []
for _ in range(N):
    A.append(list(map(int,sys.stdin.readline().split())))

def pooling(A,row,col,N):
    if N > 2:
        N = N // 2
        lt = pooling(A,row,col,N)
        rt = pooling(A,row+N,col,N)
        lb = pooling(A,row,col+N,N)
        rb = pooling(A,row+N,col+N,N)
        answer = [lt, rt ,lb, rb]
        answer.sort()
        return answer[-2]
    else:
        new = []
        for i in range(row,row+N):
            for j in range(col,col+N):
               new.append(A[i][j])
        new.sort()
        return new[-2]

print(pooling(A,0,0,N))