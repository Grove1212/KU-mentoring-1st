n, m = map(int, input().split())

lst = []

def dfs(start):
    if len(lst) == m:  
        print(' '.join(map(str, lst)))
        return

    for j in range(1, n+1):
        lst.append(j)
        dfs(j)
        lst.pop()

dfs(1)
