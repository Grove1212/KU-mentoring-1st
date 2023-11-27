#include <iostream>
using namespace std;

struct Node {
	Node* nextNode;
	Node* prevNode;
	int key;
	string data;
	Node(int key, string str) {
		this->key = key;
		data = str;
		nextNode = nullptr;
		prevNode = nullptr;
	}
};

class HashMap {
	Node* arr[13] = {nullptr,};
public:
	friend Node;
	int hashFunction(int key);
	void insert(int key, string str);
	Node* find(int key);
	void erase(int key);
	void print();
};

int HashMap::hashFunction(int key) {
	//�Ҽ��� ���� ������ = value
	return key % 13;
}
void HashMap::insert(int key, string str) {
	int value = hashFunction(key);
	Node* newNode = new Node(key, str);
	if (arr[value] != nullptr) {
		// value ���� �ߺ��� �� chaining		
		newNode->nextNode = arr[value]->nextNode;
		arr[value]->nextNode = newNode;
		newNode->nextNode->prevNode = newNode;
	}
	else arr[value] = newNode;
}
Node* HashMap::find(int key) {
	int value = hashFunction(key);
	if (arr[value] == nullptr) {
		cout << "ã�� ���� �������� �ʽ��ϴ�.\n";
		return nullptr;
	}
	else if (arr[value]->nextNode == nullptr) {
		//�� �ߺ��� ���� chaining�Ͼ�� �ʾ��� ��
		return arr[value];
	}
	else {
		//�� �ߺ��� �Ͼ chaining �Ͼ�� ��
		Node* curNode = arr[value];
		while (curNode->key != key) {
			if (curNode->nextNode == nullptr) {
				cout << "ã�� ���� �������� �ʽ��ϴ�.\n";
				return nullptr;
			}
			curNode = curNode->nextNode;
		}
		return curNode;
	}
}
void HashMap::erase(int key) {
	Node* curNode = find(key);
	if (curNode->prevNode == nullptr) {
		//chiaining�� ù��° �罽�� ��
		int value = hashFunction(key);
		arr[value]->nextNode = curNode->nextNode;
		curNode->nextNode->prevNode = nullptr;
	}
	else {
		//chaining�� n��° �罽�� ��
		curNode->prevNode->nextNode = curNode->nextNode;
		curNode->nextNode->prevNode = curNode->prevNode;
	}
}
void HashMap::print() {
	for (int i = 0; i < 13; i++) {
		if (arr[i] != nullptr) {
			cout << arr[i]->key << " : " << arr[i]->data << endl;
			//chaing�� �Ͼ�� �� -> linkedlist ���� ���
			if (arr[i]->nextNode != nullptr) {
				Node* curNode = arr[i]->nextNode;
				while (curNode->nextNode != nullptr) {
					cout << curNode->key << " : " << curNode->data << endl;
					curNode = curNode->nextNode;
				}
			}
		}
	}
	return;
}

int main() {
	HashMap hm;

	hm.insert(43, "����");
	hm.insert(47, "�ٳ���");
	hm.insert(23, "ü��");
	hm.insert(30, "����");
	hm.insert(17, "����");

	hm.print();

}