#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node* parent;
};

class BinarySearchTree {
	Node* root;
public:
	BinarySearchTree() { root = nullptr; }
	void insert(int k);
	Node* find(int k);
	void swap(Node* a, Node* b);
	void erase(int k);
	void erase(Node* node);
	void print(Node* node);
	Node* getRoot() { return root; }
};

void BinarySearchTree::insert(int k) {
	Node* addNode = new Node;
	if (root == nullptr) {
		addNode->value = k;
		addNode->parent = nullptr;
		addNode->left = nullptr;
		addNode->right = nullptr;
		root = addNode;
		return;
	}

	Node* curNode = root;
	while (true) {
		if (curNode->value > k) { // 기준 노드보다 작다면
			if (curNode->left == nullptr) { // 노드 연결
				addNode->value = k;
				addNode->parent = curNode;
				addNode->left = nullptr;
				addNode->right = nullptr;
				curNode->left = addNode;
				return;
			}
			else {
				curNode = curNode->left;
			}			
		}
		else {// 기준 노드보다 크다면
			if (curNode->right == nullptr) {
				addNode->value = k;
				addNode->parent = curNode;
				addNode->left = nullptr;
				addNode->right = nullptr;
				curNode->right = addNode;
				return;
			}
			else {
				curNode = curNode->right;
			}			
		}
	}
}
Node* BinarySearchTree::find(int k) {
	Node* curNode = root;
	if (curNode == nullptr) {
		return nullptr;
	}

	while (true) {
		while (curNode->value > k) {
			curNode = curNode->left;
		}
		while (curNode->value <= k) {
			if (curNode->value == k) {
				return curNode;
			}
			curNode = curNode->right;
		}
		if (curNode == nullptr) return nullptr;
	}
}
void BinarySearchTree::swap(Node* a, Node* b) {
	Node* tmp = new Node;
	//a의 부모 노드의 왼쪽 자식이 a라면
	if (a->parent->left == a) {
		a->parent->left = b;
	}
	//a의 부모 노드의 왼쪽 자식이 b라면
	else {
		a->parent->right = b;
	}

	//b의 부모 노드의 왼쪽 자식이 b라면
	if (b->parent->left == b) {
		b->parent->left = a;
	}
	//b의 부모 노드의 왼쪽 자식이 a라면
	else {
		b->parent->right = a;
	}

	tmp->value = b->value;
	b->value = a->value;
	a->value = tmp->value;

	tmp->parent = b->parent;
	b->parent = a->parent;
	a->parent = tmp->parent;

	tmp->left = b->left;
	b->left = a->left;
	a->left = tmp->left;

	tmp->right = b->right;
	b->right = a->right;
	a->right = tmp->right;

	delete(tmp);
}
void BinarySearchTree::erase(int k) {
	Node* delNode = find(k);
	//BST에 해당 원소가 없다면 종료
	if (delNode == nullptr) {
		return;
	}

	//해당 원소가 리프 노드라면
	if (delNode->left == nullptr && delNode->right == nullptr) {
		//해당 원소의 부모노드에서 해당 원소 제거
		if (delNode->parent->left == delNode) delNode->parent->left = nullptr;
		else delNode->parent->right = nullptr;
	}
	//해당 원소가 오른쪽 자식만 있을 때
	else if (delNode->left == nullptr) {
		//del노드가 부모노드의 왼쪽 자식이라면
		if (delNode->parent->left == delNode) {
			delNode->parent->left = delNode->right;
		}
		//del노드가 부모노드의 왼쪽 자식이라면
		else {
			delNode->parent->right = delNode->right;
		}
		delNode->right->parent = delNode->parent;
	}
	//해당 원소가 왼쪽 자식만 있을 때
	else if (delNode->right == nullptr) {
		//del노드가 부모노드의 왼쪽 자식이라면
		if (delNode->parent->left == delNode) {
			delNode->parent->left = delNode->left;
		}
		//del노드가 부모노드의 오른쪽 자식이라면
		else {
			delNode->parent->right = delNode->left;
		}
		delNode->left->parent = delNode->parent;
	}
	//해당 원소가 두 자식 다 있을 때 오른쪽 서브트리에서 제일 작은값과 교체
	else {
		Node* curNode = delNode->right;
		while (curNode->left != nullptr) {
			curNode = curNode->left;
		}

		swap(curNode, delNode);

		if (delNode->parent->left == delNode) delNode->parent->left = nullptr;
		else delNode->parent->right = nullptr;
	}
	delete(delNode);
}
void BinarySearchTree::erase(Node* node) {
	//해당 원소가 리프 노드라면
	if (node->left == nullptr && node->right == nullptr) {
		//해당 원소의 부모노드에서 해당 원소 제거
		if (node->parent->left == node) node->parent->left = nullptr;
		else node->parent->right = nullptr;
	}
	//해당 원소가 오른쪽 자식만 있을 때
	else if (node->left == nullptr) {
		//del노드가 부모노드의 왼쪽 자식이라면
		if (node->parent->left == node) {
			node->parent->left = node->right;
		}
		//del노드가 부모노드의 왼쪽 자식이라면
		else {
			node->parent->right = node->right;
		}
		node->right->parent = node->parent;
	}
	//해당 원소가 왼쪽 자식만 있을 때
	else if (node->right == nullptr) {
		//del노드가 부모노드의 왼쪽 자식이라면
		if (node->parent->left == node) {
			node->parent->left = node->left;
		}
		//del노드가 부모노드의 오른쪽 자식이라면
		else {
			node->parent->right = node->left;
		}
		node->left->parent = node->parent;
	}
	//해당 원소가 두 자식 다 있을 때 오른쪽 서브트리에서 제일 작은값과 교체
	else {
		Node* curNode = node->right;
		while (node->left != nullptr) {
			node = node->left;
		}

		swap(curNode, node);

		if (node->parent->left == node) node->parent->left = nullptr;
		else node->parent->right = nullptr;
	}
	delete(node);
}
void BinarySearchTree::print(Node* node) {
	//LDR 방식 서치
	if (node == nullptr)return;

	print(node->left);
	cout << node->value;
	print(node->right);
}

int main() {
	BinarySearchTree* bst = new BinarySearchTree();
	bst->insert(5);
	bst->insert(2);
	bst->insert(3);
	bst->insert(4);
	bst->insert(1);
	bst->insert(6);
	bst->insert(7);

	bst->print(bst->getRoot());
	cout << '\n';

	bst->erase(3);
	bst->print(bst->getRoot());

	cout << '\n';
	bst->insert(3);
	bst->print(bst->getRoot());
	cout << '\n';
	bst->insert(3);
	bst->print(bst->getRoot());
	cout << '\n';

	bst->erase(bst->find(3));
	bst->print(bst->getRoot());
	cout << '\n';

	cout << bst->find(3)->value;
}