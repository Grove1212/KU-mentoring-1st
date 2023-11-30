#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* next;
	Node(int val = NULL) {
		key = val;
		next = nullptr;
	}
};

class HashMap {
	int size;
	Node* hashTable;
public:
	HashMap() {
		size = 13;
		hashTable = new Node[size];
	}
	~HashMap() {
		for (int i = 0; i < size; i++)
			Destruct(hashTable[i].next);
		delete[] hashTable;
	}
	void Destruct(Node* tmp) {
		if (tmp != nullptr) {
			Destruct(tmp->next);
			delete tmp;
		}
	}
	void insert(int key);
	void print();
};

void HashMap::insert(int key) {
	int n = key % size;
	if (hashTable[n].key == NULL) {
		hashTable[n].key = key;
	}
	else {
		Node* tmp = new Node;
		tmp->key = key;
		if (hashTable[n].next == nullptr) {
			hashTable[n].next = tmp;
		}
		else {
			Node* tmp2 = hashTable[n].next;
			while (tmp2->next != nullptr)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
	}
}

void HashMap::print() {
	Node* tmp;
	for (int i = 0; i < size; i++) {
		cout << hashTable[i].key;
		tmp = hashTable[i].next;
		while (tmp != nullptr) {
			cout << ' ' << tmp->key;
			tmp = tmp->next;
		}
		cout << "\n";
	}
}

int main() {
	HashMap h;

	h.insert(1);
	h.insert(14);
	h.insert(2);
	h.print();
}