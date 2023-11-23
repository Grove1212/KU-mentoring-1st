# import sys
#
# def binary_search(arr,x,a,b):
#     if a>b: return None
#     m = (a+b)//2
#     if x == arr[m]:
#         return arr[a:b+1].count(x)
#     elif x > arr[m]:
#         return binary_search(arr,x,m+1,b)
#     else: #x < arr[m]
#         return binary_search(arr,x,0,m-1)
#
#
#
N = int(input())
A= list(map(int,input().split()))
A.sort()
M = int(input())
B= list(map(int,input().split()))

# 2진탐색(시간초과)

# for j in B:
#     a = binary_search(A,j,0,N-1)
#     if a is not None:
#         print(a, end=' ')
#     else:
#         print(0,end=' ')

# 해시 이용

hash = {}

for i in A:
    if i in hash:
        hash[i] += 1
    else:
        hash[i] = 1

for i in B:
    if i in hash:
        print(hash[i],end=' ')
    else:
        print(0,end=' ')
