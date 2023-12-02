def check(x, y, size):
    global paper, result

    start = paper[x][y]
    same = True

    for i in range(x, x + size):
        if not same:
            break
        for j in range(y, y + size):
            if paper[i][j] != start:
                same = False
                break

    if same:
        result[start] += 1
    else:
        size //= 3
        for i in range(3):
            for j in range(3):
                check(x + i * size, y + j * size, size)

# 입력 받기
n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]

# 결과 저장할 변수 초기화
result = {-1: 0, 0: 0, 1: 0}

# 함수 호출
check(0, 0, n)

# 결과 출력
for key in result:
    print(result[key])
