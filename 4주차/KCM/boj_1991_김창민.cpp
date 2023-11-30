#include <iostream>
#include <map>
using namespace std;

struct Node {
	char left, right;
};

map<char, Node*> tree;

void preorder(char);
void inorder(char);
void postorder(char);
void destructor(char);

int main() {
	int n;
	char root, left, right;

	cin >> n;
	for (int i = 0; i < n; i++) {
		Node* node = new Node;
		cin >> root >> left >> right;
		node->left = left;
		node->right = right;
		tree.insert({ root, node });
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	destructor('A');
}

void preorder(char c) {
	if (c != '.') {
		cout << c;
		preorder(tree[c]->left);
		preorder(tree[c]->right);
	}
}

void inorder(char c) {
	if (c != '.') {
		inorder(tree[c]->left);
		cout << c;
		inorder(tree[c]->right);
	}
}

void postorder(char c) {
	if (c != '.') {
		postorder(tree[c]->left);
		postorder(tree[c]->right);
		cout << c;
	}
}

void destructor(char c) {
	if (c != '.') {
		destructor(tree[c]->left);
		destructor(tree[c]->right);
		delete tree[c];
	}
}