
n, m = map(int, input().split())

lst = []

def dfs(start):
    if len(lst) == m:  
        print(' '.join(map(str, lst)))
        return

    for j in range(start, n+1):
        if j not in lst:
            lst.append(j)
            dfs(j+1)
            lst.pop()

dfs(1)
