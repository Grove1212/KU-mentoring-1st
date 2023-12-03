def apply_pooling(matrix):
    size = len(matrix)
    
    # 종료 조건: 행렬 크기가 1x1이면 해당 값을 반환
    if size == 1:
        return matrix[0][0]
    
    new_matrix = []
    for i in range(0, size, 2):
        row = []
        for j in range(0, size, 2):
            square = [matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1]]
            square.sort()
            row.append(square[2])  # 2번째로 큰 값을 선택
        new_matrix.append(row)
    
    # 재귀적으로 222-풀링 적용
    return apply_pooling(new_matrix)

# 입력 받기
N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

# 222-풀링 적용 후 결과 출력
result = apply_pooling(matrix)
print(result)
