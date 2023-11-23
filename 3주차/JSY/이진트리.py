class Node:
    def __init__(self,key):
        self.key = key
        self.parent = self.left = self.right = None

    def __str__(self):
        return str(self.key)

class Tree:
    def __init__(self):
        self.root = None
        self.size = 0

    def __len__(self):
        return self.size

    def preorder(self,v):
        if v:
            print(v.key,end='-')
            self.preorder(v.left)
            self.preorder(v.right)

    def inorder(self,v):
        if v:
            self.inorder(v.left)
            print(v.key, end='-')
            self.inorder(v.right)

    def postorder(self,v):
        if v:
            self.postorder(v.left)
            self.postorder(v.right)
            print(v.key,end='-')

    def find_loc(self,key):
        if self.size == 0 : return None
        p = None # 찾고자 하는 노드의 Parent
        v = self.root
        while v:
            if v.key == key:
                return v
            else:
                if v.key < key:
                    p = v
                    v = v.right
                else:
                    p = v
                    v = v.left
        return p

    def search(self,key):
        p = self.find_loc(key)
        if p and p.key == key:
            return p
        else:
            return None