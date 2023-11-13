//stack by singlyLinkedList

#include <iostream>
using namespace std;

struct Node {
	Node* nextNode;
	string data;
	struct Node(string s = NULL) {
		data = s;
		nextNode = nullptr;
	}
};

class SinglyLinkedList {
	Node* head;
	Node* tail;
public:
	SinglyLinkedList();
	void push_back(string s);
	void push_front(string s);
	void insert(int idx, string s);
	void insert(int idx, string s[], int size);
	Node* front();
	Node* back();
	void Delete(int idx);
	void Delete(int idx, int size);
	int size();
	void debug();
};
void SinglyLinkedList::debug() {
	cout << "<<head부터 tail까지 출력>>\n";
	Node* ptr = head;
	while (true) {
		cout << ptr->data << endl;
		if (ptr->nextNode == nullptr) break;
		ptr = ptr->nextNode;
	}
}

SinglyLinkedList::SinglyLinkedList() {
	head = nullptr;
	tail = nullptr;
}

void SinglyLinkedList::push_back(string s) {
	Node* a = new Node(s);
	if (head == nullptr)
		head = a;
	if (tail == nullptr) {
		tail = a;
	}
	else {
		tail->nextNode = a; // 이전노드의 포인터는 새로운 노드를 가리킴
		tail = a; // tail은 이제 새로운 노드를 가리킴
	}
}
void SinglyLinkedList::push_front(string s) {
	Node* a = new Node(s);
	if (head == nullptr)
		head = a;
	if (tail == nullptr)
		tail = a;
	else {
		a->nextNode = head; //새로운 노드의 포인터는 head를 가리킴
		head = a; // head는 새로운 노드의 주소
	}
}
void SinglyLinkedList::insert(int idx, string s) {
	int i = 1;
	Node* ptr = head;
	while (i == (idx - 1)) {
		ptr = ptr->nextNode;
		i++;
	}
	Node* a = new Node(s);
	a->nextNode = ptr->nextNode;
	ptr->nextNode = a;
}
void SinglyLinkedList::insert(int idx, string s[],int size) {
	int i = 1;
	Node* ptr = head;
	while (i == (idx - 1)) {
		ptr = ptr->nextNode;
		i++;
	}

	for (int i = 0; i < size; i++) {
		Node* a = new Node(s[i]);
		a->nextNode = ptr->nextNode;
		ptr->nextNode = a;
		ptr = a;
	}
}
Node* SinglyLinkedList::front() {
	return head;
}
Node* SinglyLinkedList::back() {
	return tail;
}
void SinglyLinkedList::Delete(int idx) {
	int i = 1;
	Node* ptr1 = head;
	while (i == idx - 1) {
		ptr1 = ptr1->nextNode;
		i++;
	}
	Node* ptr2 = ptr1->nextNode;
	ptr1->nextNode = ptr2->nextNode;
}
void SinglyLinkedList::Delete(int idx, int size) {
	int i = 1;
	Node* ptr1 = head;
	while (i == idx - 1) { // idx 위치의 노드를 찾음
		ptr1 = ptr1->nextNode;
		i++;
	}
	Node* ptr2 = ptr1;
	for (int i = 0; i < size; i++) {
		ptr2 = ptr2->nextNode;
	}
	ptr1->nextNode = ptr2->nextNode;
}
int SinglyLinkedList::size() {
	int count = 1;
	Node* ptr = head;
	while (true) {
		if (ptr->nextNode == nullptr) break;
		ptr = ptr->nextNode;
		count++;
	}
	return count;
}

class Stack {
	SinglyLinkedList list;
	int topIdx = -1;
public:
	void push(string t) {
		list.push_back(t);
		topIdx++;
	}
	void pop() {
		list.Delete(topIdx);
		topIdx--;
	}
	int top() {
		return topIdx;
	}
	int size() {
		return list.size();
	}
};