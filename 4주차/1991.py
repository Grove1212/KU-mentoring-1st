import sys

n=int(sys.stdin.readline())
tree = {}

for i in range(n):
    head,left,right=sys.stdin.readline().split()
    tree[head]=left,right

def preorder_traversal(node):
    if node!='.':
        print(node,end='')
        preorder_traversal(tree[node][0])
        preorder_traversal(tree[node][1])

def inorder_traversal(node):
    if node!='.':
        inorder_traversal(tree[node][0])
        print(node,end="")
        inorder_traversal(tree[node][1])

def postorder_traversal(node):
    if node!='.':
        postorder_traversal(tree[node][0])
        postorder_traversal(tree[node][1])
        print(node,end="")

preorder_traversal('A')
print()
inorder_traversal('A')
print()
postorder_traversal('A')
