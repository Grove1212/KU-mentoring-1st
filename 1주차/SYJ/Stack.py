# Stack 구현
#
# Stack은 First In, Last Out이라는 특성을 가지는 자료구조입니다.
# 앞에서 구현했던 가변 배열, 연결 리스트 방식으로 Stack을 구현해보세요!
#
# [참고1](https://www.cs.usfca.edu/~galles/visualization/StackArray.html)
#
# [참고2](https://www.cs.usfca.edu/~galles/visualization/StackLL.html)
#
# 지원해야하는 연산은 아래와 같습니다.
#
# 1. `push(Data data)`: stack에 data삽입 $\rightarrow$ $O(1)$
# 2. `top()`: stack의 top에 있는 원소를 출력 (삭제가 아니다) $\rightarrow$ $O(1)$
# 3. `pop()`: stack의 top에 있는 원소를 삭제한다. $\rightarrow$ $O(1)$

class Node:
    def __init__(self,key):
        self.key = key
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self,key):
        newNode = Node(key)
        newNode.next = self.head
        self.head = newNode
        self.size += 1
    def top(self):
        return self.head.key

    def pop(self,key):
        key = None
        if len(self) > 0:
            key = self.head.key
            self.head = self.head.next
            self.size -= 1
        return key

