//doubly linked list
#include <iostream>
using namespace std;

struct Node {
	Node* prev;
	Node* next;
	string data;
	struct Node(string s = NULL) {
		data = s;
		prev = nullptr;
		next = nullptr;
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
	head = nullptr;// 더미 노드
	tail = new Node(" ");
}
void DoublyLinkedList::push_back(string s) {
	Node* a = new Node(s);
	if (head == nullptr)
		head = a;
	if (tail == nullptr)
		tail = a;
	else {
		tail->next = a;// 이전노드의 포인터는 새로운 노드를 가리킴
		a->prev = tail;
		tail = a; // tail은 이제 새로운 노드를 가리킴
	}
}
void DoublyLinkedList::push_front(string s) {
	Node* a = new Node(s);
	if (head == nullptr)
		head = a;
	if (tail == nullptr)
		tail = a;
	else {
		head->prev = a;
		a->next = head; //새로운 노드의 포인터는 head를 가리킴
		head = a; // head는 새로운 노드의 주소
	}
}
void DoublyLinkedList::insert(int idx, string s) {
	int i = 1;
	Node* ptr = head;
	while (i == (idx - 1)) {
		ptr = ptr->next;
		i++;
	}
	Node* a = new Node(s);
	a->next = ptr->next;
	ptr->next = a;
}
void DoublyLinkedList::insert(int idx, string s[], int size) {
	int i = 1;
	Node* ptr = head;
	while (i == (idx - 1)) {
		ptr = ptr->next;
		i++;
	}

	for (int i = 0; i < size; i++) {
		Node* a = new Node(s[i]);
		a->next = ptr->next;
		ptr->next = a;
		ptr = a;
	}
}
string DoublyLinkedList::front() {
	return head->data;
}
string DoublyLinkedList::back() {
	return tail->data;
}
void DoublyLinkedList::Delete(int idx) {
	int i = 1;
	Node* ptr1 = head;
	while (i == idx - 1) {
		ptr1 = ptr1->next;
		i++;
	}
	Node* ptr2 = ptr1->next;
	ptr1->next = ptr2->next;
}
void DoublyLinkedList::Delete(int idx, int size) {
	int i = 1;
	Node* ptr1 = head;
	while (i == idx - 1) { // idx 위치의 노드를 찾음
		ptr1 = ptr1->next;
		i++;
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
	a.insert(2, hi,4);
	a.debug();

	a.Delete(2, 4);
	a.debug();
}