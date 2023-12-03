import math
def check(A,n,row,col):
    start = A[row][col]

    for i in range(row, row+n):
        for j in range(col, col+n):
            if A[i][j] != start:
                div = n // 3
                check(A, div, row, col)
                check(A, div, row, col + div)
                check(A, div, row, col + 2*div)
                check(A, div, row + div, col)
                check(A, div, row + div, col + div)
                check(A, div, row + div, col + 2 * div)
                check(A, div, row + 2 * div, col)
                check(A, div, row + 2 * div, col + div)
                check(A, div, row + 2 * div, col + 2 * div)
                return
    result[start] += 1




N = int(input())
A = []
result = {-1:0, 0:0, 1:0}
for _ in range(N):
    A.append(list(map(int,input().split())))
check(A,N,0,0)
for i in result.values():
    print(i)