class Node:
    def __init__(self,key):
        self.key = key
        self.prev = self
        self.next = self

    def __str__(self):
        return str(self.key)

class DoublyLinkedList:
    def __init__(self):
        self.head = Node()
        self.size = 0

    def __iter__(self):
        v = self.head
        while v!= None:
            yield v
            v = v.next

    def __str__(self):
        s = " "
        v = self.head
        while v:
            s += str(v.key) + "->"
            v = v.next
        s += None
        return s

    def __len__(self):
        return self.size

    def printList(self):
        v = self.head.next
        print("h -> ", end="")
        while v != self.head:
            print(str(v.key)+" -> ", end="")
            v = v.next
        print("h")

    def splice(self,a,b,x):
        if a == None or b == None or x == None:
            return
        a.prev.next = b.next
        b.next.prev = a.prev
        x.next = a
        x.next.prev = b
        a.prev = x
        b.next = x.next

    def MoveAfter(self,a,x):
        self.splice(a,a,x)
    def MoveBefore(self,a,x):
        self.splice(a,a,x.prev)

    def insetAfter(self,a,x):
        self.MoveAfter(Node(a),x)
        self.size += 1
    def insertBefore(self,a,x):
        self.MoveBefore(Node(a),x)
        self.size += 1
    def pushFront(self,key):
        self.insertAfter(self.head,key)
        self.size += 1
    def pushBack(self,key):
        self.insertBefore(self.head,key)
        self.size += 1

    def search(self, key):
        v = self.head
        while v.next != self.head:
            if v.key == key:
                return v
            v = v.next
        if v.key == key:
            return v
        return None


    def deleteNode(self, x):  # delete x
        if x == None or x == self.head:
            return
        # 노드 x를 리스트에서 분리해내기
        x.prev.next, x.next.prev = x.next, x.prev
        self.size -= 1

    def popfront(self):
        if self.head.next == self.head:
            return None
        key = self.head.next.key
        self.deleteNode(self.head.next)
        return key

    def popback(self):
        if self.head.prev == self.head:
            return None
        key = self.head.prev.key
        self.head.prev = self.head.prev.prev

    def size(self):
        return self.size