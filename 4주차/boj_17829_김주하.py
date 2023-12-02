def pooling(matrix):
    if len(matrix) == 1:
        return matrix[0][0]

    n = len(matrix)
    new_matrix = [[0] * (n // 2) for _ in range(n // 2)]

    for i in range(0, n, 2):
        for j in range(0, n, 2):
            sub_matrix = [matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1]]
            sub_matrix.sort(reverse=True)
            new_matrix[i // 2][j // 2] = sub_matrix[1]

    return pooling(new_matrix)

# 입력 받기
n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

# 결과 출력
result = pooling(matrix)
print(result)
