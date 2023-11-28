class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def preorder_traversal(root):
    if root:
        print(root.data, end='')
        preorder_traversal(root.left)
        preorder_traversal(root.right)

def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.data, end='')
        inorder_traversal(root.right)

def postorder_traversal(root):
    if root:
        postorder_traversal(root.left)
        postorder_traversal(root.right)
        print(root.data, end='')

def build_tree(node_info):
    nodes = {}
    for info in node_info:
        data, left, right = info
        if data not in nodes:
            nodes[data] = Node(data)
        if left != '.':
            nodes[left] = Node(left)
            nodes[data].left = nodes[left]
        if right != '.':
            nodes[right] = Node(right)
            nodes[data].right = nodes[right]
    return nodes['A']

# 입력 받기
N = int(input())
node_info = [input().split() for _ in range(N)]

# 이진 트리 생성
root = build_tree(node_info)

# 전위 순회 출력
preorder_traversal(root)
print()

# 중위 순회 출력
inorder_traversal(root)
print()

# 후위 순회 출력
postorder_traversal(root)
