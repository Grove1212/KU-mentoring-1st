def count_paper(matrix, size, row, col):
    # 종이의 모든 값이 같은지 확인
    check_value = matrix[row][col]
    for i in range(row, row + size):
        for j in range(col, col + size):
            if matrix[i][j] != check_value:
                return False
    
    return True

def cut_paper(matrix, size, row, col, result):
    # 종이가 모두 같은 수일 경우
    if count_paper(matrix, size, row, col):
        result[matrix[row][col] + 1] += 1
        return

    # 9개의 영역으로 나누어서 재귀적으로 호출
    new_size = size // 3
    for i in range(3):
        for j in range(3):
            cut_paper(matrix, new_size, row + i * new_size, col + j * new_size, result)

# 입력 받기
N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

# -1, 0, 1로 채워진 종이의 개수를 세는 변수
result = [0, 0, 0]

# 재귀 호출 시작
cut_paper(matrix, N, 0, 0, result)

# 결과 출력
for count in result:
    print(count)
