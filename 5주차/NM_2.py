N, M = map(int,input().split())

A = []
for i in range(1,N+1):
    A.append(i)

B = []

def permutation():
        if len(B) == M:
            for i in B:
                print(i,end=' ')
            print()
        else:
            for i in A:
                    B.append(i)
                    permutation()
                    B.pop()
permutation()