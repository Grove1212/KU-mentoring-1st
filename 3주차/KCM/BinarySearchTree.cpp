#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int val = NULL) {
		data = val;
		left = right = nullptr;
	}
};

class BinarySearchTree {
private:
	Node* root;
	int size;
public:
	BinarySearchTree() {
		root = new Node;
		size = 0;
	}
	~BinarySearchTree() {
		B(root);
	}
	void B(Node* tmp) {
		B(tmp->left);
		B(tmp->right);
		delete tmp;
	}
	void insert(int n);
	void del(int n);
};

void BinarySearchTree::insert(int n){
	Node* tmp = root;
	while (tmp != nullptr) {
		if (tmp->data == NULL) {
			tmp->data = n;
			break;
		}
		else if (tmp->data > n) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}

	if (tmp == nullptr) {
		tmp = new Node;
		tmp->data = n;
	}
}

void BinarySearchTree::del(int n) {
	
}

int main() {

}