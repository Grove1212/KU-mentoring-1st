//doubly linked list
#include <iostream>
using namespace std;

struct Node {
	Node* prev;
	Node* next;
	string data;
	struct Node(string s = NULL) {
		data = s;
		prev = nullptr; // 이전노드
		next = nullptr; // 다음노드
	}
};

class DoublyLinkedList {
	Node* head;
	Node* tail;
public:
	DoublyLinkedList();
	void push_back(string s);
	void push_front(string s);
	void insert(int idx, string s);
	void insert(int idx, string s[], int size);
	string front();
	string back();
	void Delete(int idx);
	void Delete(int idx, int size);
	int size();
	void debug();
};
void DoublyLinkedList::debug() {
	cout << "<<head부터 tail까지 출력>>\n";
	Node* ptr = head;
	while (true) {
		cout << ptr->data << endl;
		if (ptr->next == nullptr) break;
		ptr = ptr->next;
	}
}
DoublyLinkedList::DoublyLinkedList() {
	head = new Node(" ");
	tail = new Node(" ");
	head->next = tail;
	tail->prev = head; //head와 tail의 포인터가 서로를 향한다.
}
void DoublyLinkedList::push_back(string s) {
	Node* a = new Node(s);
	Node* tmp = tail->prev;
	tail->prev->next = a; // tail의 이전노드와 a의 prev를 연결
	tail->prev = a;
	a->prev = tmp;
	a->next = tail;
}
void DoublyLinkedList::push_front(string s) {
	Node* a = new Node(s);
	Node* tmp = head->next;
	head->next->prev = a;
	head->next = a;
	a->prev = head; // head의 다음노드와 a의 prev를 연결
	a->next = tmp;
}
void DoublyLinkedList::insert(int idx, string s) {
	Node* ptr = head;
	for (int i = 0; i < idx; i++) {
		ptr = ptr->next;
	}
	Node* a = new Node(s);
	a->next = ptr->next;
	ptr->next = a;
	ptr->next->prev = a;
	a->prev = ptr;
}
void DoublyLinkedList::insert(int idx, string s[], int size) {
	Node* ptr = head;
	for(int i = 0; i < idx; i++) {
		ptr = ptr->next;
	}

	for (int i = 0; i < size; i++) {
		Node* a = new Node(s[i]);
		a->next = ptr->next;
		ptr->next = a;
		ptr->next->prev = a;
		a->prev = ptr;
	}
}
string DoublyLinkedList::front() {
	return head->data;
}
string DoublyLinkedList::back() {
	return tail->data;
}
void DoublyLinkedList::Delete(int idx) {
	Node* ptr1 = head;
	for (int i = 0; i < idx; i++) { // idx 위치의 노드를 찾음
		ptr1 = ptr1->next;
	}
	Node* ptr2 = ptr1->next;
	ptr1->next = ptr2->next;
}
void DoublyLinkedList::Delete(int idx, int size) {
	Node* ptr1 = head;
	for(int i = 0; i <idx; i++) { // idx 위치의 노드를 찾음
		ptr1 = ptr1->next;
	}
	Node* ptr2 = ptr1;
	for (int i = 0; i < size; i++) {
		ptr2 = ptr2->next;
	}
	ptr1->next = ptr2->next;
}
int DoublyLinkedList::size() {
	int count = 1;
	Node* ptr = head;
	while (true) {
		if (ptr->next == nullptr) break;
		ptr = ptr->next;
		count++;
	}
	return count;
}

int main() {
	DoublyLinkedList a;
	string k("hello");
	string b("1");
	string c("2");
	string d("3");
	string e("4");
	a.push_back(k);
	a.push_back(b);
	a.push_back(c);
	a.push_back(d);
	a.push_back(e);

	string hi[] = { "a","b","c","d" };
	a.insert(2, hi, 4);
	a.debug();

	a.Delete(2, 4);
	a.debug();
}