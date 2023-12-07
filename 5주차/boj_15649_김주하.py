def dfs(n, lst):
    if n == M:
        re.append(lst)
        return
    for i in range(1, N + 1):
        if v[i] == 0:
            v[i] = 1
            dfs(n + 1, lst + [i])
            v[i] = 0

N, M = map(int, input().split())

re = []
v = [0] * (N + 1)  # 중복확인

dfs(0, [])
for lst in re:
    print(*lst)
