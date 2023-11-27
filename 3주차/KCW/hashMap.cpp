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
	//소수로 나눈 나머지 = value
	return key % 13;
}
void HashMap::insert(int key, string str) {
	int value = hashFunction(key);
	Node* newNode = new Node(key, str);
	if (arr[value] != nullptr) {
		// value 값이 중복될 때 chaining		
		newNode->nextNode = arr[value]->nextNode;
		arr[value]->nextNode = newNode;
		newNode->nextNode->prevNode = newNode;
	}
	else arr[value] = newNode;
}
Node* HashMap::find(int key) {
	int value = hashFunction(key);
	if (arr[value] == nullptr) {
		cout << "찾는 값이 존재하지 않습니다.\n";
		return nullptr;
	}
	else if (arr[value]->nextNode == nullptr) {
		//값 중복이 없어 chaining일어나지 않았을 때
		return arr[value];
	}
	else {
		//값 중복이 일어나 chaining 일어났을 때
		Node* curNode = arr[value];
		while (curNode->key != key) {
			if (curNode->nextNode == nullptr) {
				cout << "찾는 값이 존재하지 않습니다.\n";
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
		//chiaining의 첫번째 사슬일 때
		int value = hashFunction(key);
		arr[value]->nextNode = curNode->nextNode;
		curNode->nextNode->prevNode = nullptr;
	}
	else {
		//chaining의 n번째 사슬일 때
		curNode->prevNode->nextNode = curNode->nextNode;
		curNode->nextNode->prevNode = curNode->prevNode;
	}
}
void HashMap::print() {
	for (int i = 0; i < 13; i++) {
		if (arr[i] != nullptr) {
			cout << arr[i]->key << " : " << arr[i]->data << endl;
			//chaing이 일어났을 때 -> linkedlist 따라 출력
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

	hm.insert(43, "수박");
	hm.insert(47, "바나나");
	hm.insert(23, "체리");
	hm.insert(30, "포도");
	hm.insert(17, "망고");

	hm.print();

}