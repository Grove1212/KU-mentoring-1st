N, M = map(int,input().split())
N_arr = list(map(int,input().split()))
N_arr.sort()

B = []

def permutation():
        if len(B) == M:
            for i in B:
                print(i,end=' ')
            print()
        else:
            for i in N_arr:
                    B.append(i)
                    permutation()
                    B.pop()
permutation()