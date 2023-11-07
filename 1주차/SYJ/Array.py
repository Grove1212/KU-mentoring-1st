# 가변적인 크기를 가지는 배열을 구현해야합니다.
# 동적할당을 이용하여 가변 배열 클래스를 만들어보세요.
#
# 지원해야하는 연산은 다음과 같습니다.
#
# 1. `push_back(T data)` : 현재 가변 배열 뒤에 원소를 삽입
# 2. `pop_back()` : 현재 가변 배열 뒤의 원소를 삭제
# 3. `insert(Iterator index, T data)`: 가변 배열의 index위치에 원소를 삽입합니다. index위치의 원소를 포함하여 $k$($k$ > index) 위치에 있는 원소들은 뒤로 밀립니다.
# 4. `delete(Iterator index)`: 가변 배열의 index위치에 있는 원소를 삭제합니다.
# 5. `at(Iterator i)`: $i$ 인덱스에 존재하는 원소의 레퍼런스(or 포인터)를 반환합니다.
# 6. `size()`: 현재 가변배열의 길이를 반환합니다.
# 7. `clear()`: 가변 배열을 초기화합니다.

class Dynamic_array:
    def __init__(self,s):
        self.array = list(s)

    def push_back(self,x):
        self.array.append(x)

    def pop_back(self):
        self.array.pop()

    def insert(self,i,x):
        self.array.insert(i,x)

    def delete(self,x):
        self.pop(self.array.index(x))

    def at(self,x):
        print([i for i,value in enumerate(self.array) if value == x])

    def size(self):
        return len(self.array)

    def clear(self):
        self.array.clear()

s = [1,2,3,4,5,6]
S = Dynamic_array(s)
S.push_back(3)
S.push_back(4)
S.push_back(5)
print(S.array)
print(S.at(5))