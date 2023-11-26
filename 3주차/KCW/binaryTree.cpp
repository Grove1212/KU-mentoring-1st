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
		if (curNode->value > k) { // ���� ��庸�� �۴ٸ�
			if (curNode->left == nullptr) { // ��� ����
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
		else {// ���� ��庸�� ũ�ٸ�
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
	//a�� �θ� ����� ���� �ڽ��� a���
	if (a->parent->left == a) {
		a->parent->left = b;
	}
	//a�� �θ� ����� ���� �ڽ��� b���
	else {
		a->parent->right = b;
	}

	//b�� �θ� ����� ���� �ڽ��� b���
	if (b->parent->left == b) {
		b->parent->left = a;
	}
	//b�� �θ� ����� ���� �ڽ��� a���
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
	//BST�� �ش� ���Ұ� ���ٸ� ����
	if (delNode == nullptr) {
		return;
	}

	//�ش� ���Ұ� ���� �����
	if (delNode->left == nullptr && delNode->right == nullptr) {
		//�ش� ������ �θ��忡�� �ش� ���� ����
		if (delNode->parent->left == delNode) delNode->parent->left = nullptr;
		else delNode->parent->right = nullptr;
	}
	//�ش� ���Ұ� ������ �ڽĸ� ���� ��
	else if (delNode->left == nullptr) {
		//del��尡 �θ����� ���� �ڽ��̶��
		if (delNode->parent->left == delNode) {
			delNode->parent->left = delNode->right;
		}
		//del��尡 �θ����� ���� �ڽ��̶��
		else {
			delNode->parent->right = delNode->right;
		}
		delNode->right->parent = delNode->parent;
	}
	//�ش� ���Ұ� ���� �ڽĸ� ���� ��
	else if (delNode->right == nullptr) {
		//del��尡 �θ����� ���� �ڽ��̶��
		if (delNode->parent->left == delNode) {
			delNode->parent->left = delNode->left;
		}
		//del��尡 �θ����� ������ �ڽ��̶��
		else {
			delNode->parent->right = delNode->left;
		}
		delNode->left->parent = delNode->parent;
	}
	//�ش� ���Ұ� �� �ڽ� �� ���� �� ������ ����Ʈ������ ���� �������� ��ü
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
	//�ش� ���Ұ� ���� �����
	if (node->left == nullptr && node->right == nullptr) {
		//�ش� ������ �θ��忡�� �ش� ���� ����
		if (node->parent->left == node) node->parent->left = nullptr;
		else node->parent->right = nullptr;
	}
	//�ش� ���Ұ� ������ �ڽĸ� ���� ��
	else if (node->left == nullptr) {
		//del��尡 �θ����� ���� �ڽ��̶��
		if (node->parent->left == node) {
			node->parent->left = node->right;
		}
		//del��尡 �θ����� ���� �ڽ��̶��
		else {
			node->parent->right = node->right;
		}
		node->right->parent = node->parent;
	}
	//�ش� ���Ұ� ���� �ڽĸ� ���� ��
	else if (node->right == nullptr) {
		//del��尡 �θ����� ���� �ڽ��̶��
		if (node->parent->left == node) {
			node->parent->left = node->left;
		}
		//del��尡 �θ����� ������ �ڽ��̶��
		else {
			node->parent->right = node->left;
		}
		node->left->parent = node->parent;
	}
	//�ش� ���Ұ� �� �ڽ� �� ���� �� ������ ����Ʈ������ ���� �������� ��ü
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
	//LDR ��� ��ġ
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