# ## 연결 리스트 구현
#
# - (필수) 단일 연결 리스트
# - (필수) 이중 연결 리스트
# - (선택) Circular Doubly linked list
#
# 각각의 연결 리스트는 아래와 같은 연산을 지원해야합니다.
#
# 1. `push_back(Data data)`: 연결 리스트의 tail에 data를 삽입합니다.
# 2. `push_front(Data data)`: 연결 리스트의 head에 data를 삽입합니다.
# 3. `insert(Iterator it, Data data)`: it위치에 data를 삽입합니다.
# 4. `insert(Iterator it, Data data[])`: it위치에 data들을 삽입합니다.
# 5. `front(), back()`: 각각은 연결리스트의 head의 값과, tail의 값을 리턴합니다.
# 6. `delete(Iterator it)`: it 위치의 데이터를 삭제합니다.
# 7. `delete(Iterator it, Number count)`: it 위치의 데이터를 count개만큼 삭제합니다.
# 8. `size()`: 연결리스트에 존재하는 모든 노드의 수를 구합니다.

class Node:
    def __init__(self,key):
        self.key = key
        self.next = None

    def __str__(self):
        return str(self.key)

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0
    def printList(self):
        s = " "
        v = self.head
        while v:
            s += str(v.key) + "->"
            v = v.next
        s += "None"
        print(s)

    def __len__(self):
        return self.size
    def pushfront(self,key):
        new_Node = Node(key)
        new_Node.next = self.head
        self.head = new_Node
        self.size += 1

    def pushback(self,key):
        new_Node = Node(key)
        if self.size != 0:
            tail = self.head
            while tail.next != None:
                tail = tail.next
            tail.next = new_Node
        else:
            self.head = new_Node
        self.size += 1

    def insert(self, index, key):
        new_Node = Node(key)
        if len(self) == 0:
            self.head = new_Node
        elif index >= len(self):
            print("Not Appropriate function. Use pushback instead")
            return
        else:
            tail = self.head
            for i in range(index):
                tail = tail.next
            new_Node.next = tail.next
            tail.next = new_Node
        self.size += 1
        print(key,"is inserted at index[", index, "]")

    def insert_many(self,index,A):
        if len(self) == 0:
            new_Node = Node(A[0])
            self.head = new_Node
            tail = self.head
            self.size += 1
            for i in range(1,len(A)):
                new_Node = Node(A[i])
                new_Node.next = tail.next
                tail.next = new_Node
                tail = tail.next
                self.size += 1
        else:
            tail = self.head
            for i in range(index):
                tail = tail.next
            for i in range(len(A)):
                new_Node = Node(A[i])
                new_Node.next = tail.next
                tail.next = new_Node
                tail = tail.next
                self.size += 1

    def popfront(self):
        key = None
        if len(self) > 0:
            key = self.head.key
            self.head = self.head.next
            self.size -= 1
        return key

    def popback(self):
        key = None
        if self.size == 0:
            return None
        else:
            previous , tail = None, self.head
            while tail.next != None:
                previous, tail = tail, tail.next
            key = tail.key
            if self.head == tail:
                self.head = None
            else:
                previous.next = tail.next
            self.size -= 1
            return key

    def search(self,k):
        v = self.head
        while v != None:
            if v.key == k:
                return v
            v = v.next
        return None

    def remove(self, x):
        if self.size == 0 or x == None:
            return None
        elif x == self.head:
            self.popFront()
            return True
        else:
            prev = self.head
            while prev.next != x:
                prev = prev.next
            prev.next = x.next
            self.size -= 1
            return True
            
            

L = LinkedList()
while True:
    cmd = input().split()
    if cmd[0] == "pushfront":
        L.pushfront(int(cmd[1]))
        print(int(cmd[1]), "is pushed at front.")
    elif cmd[0] == "pushback":
        L.pushback(int(cmd[1]))
        print(int(cmd[1]), "is pushed at back.")
    elif cmd[0] == "insert":
        L.insert(int(cmd[1]),int(cmd[2]))
    elif cmd[0] == "insert_many":
        L.insert_many(int(cmd[1]),list(map(int, cmd[2:])))
        print(list(map(int, cmd[2:])),"is inserted at",int(cmd[1]))

    elif cmd[0] == "pushback":
        L.pushback(int(cmd[1]))
        print(int(cmd[1]), "is pushed at back.")
    elif cmd[0] == "popFront":
        x = L.popFront()
        if x == None:
            print("List is empty.")
        else:
            print(x, "is popped from front.")
    elif cmd[0] == "popBack":
        x = L.popBack()
        if x == None:
            print("List is empty.")
        else:
            print(x, "is popped from back.")
    elif cmd[0] == "search":
        x = L.search(int(cmd[1]))
        if x == None:
            print(int(cmd[1]), "is not found!")
        else:
            print(int(cmd[1]), "is found!")
    elif cmd[0] == "remove":
        x = L.search(int(cmd[1]))
        if L.remove(x):
            print(x.key, "is removed.")
        else:
            print("Key is not removed for some reason.")
    elif cmd[0] == "printList":
        L.printList()
    elif cmd[0] == "size":
        print("list has", len(L), "nodes.")
    elif cmd[0] == "exit":
        print("DONE!")
        break
    else:
        print("Not allowed operation! Enter a legal one!")
