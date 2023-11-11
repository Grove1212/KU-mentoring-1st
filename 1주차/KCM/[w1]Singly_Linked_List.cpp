#include <iostream>
using namespace std;

class Singly_Linked_List {
private:
	typedef struct Node {
		int data;
		Node* next;
	} node;
	node* head;
	node* tail;
	int list_size;
public:
	Singly_Linked_List();
	~Singly_Linked_List();

	void push_back(int data);
	void push_front(int data);
	void insert(int it, int data);
	void insert(int it, int* data, int len);
	int front();
	int back();
	void del(int it);
	void del(int it, int count);
	int size();
	void print();
};

Singly_Linked_List::Singly_Linked_List() {
	head = NULL;
	tail = NULL;
	list_size = 0;
}

Singly_Linked_List::~Singly_Linked_List() {
	node* tmp = head;
	node* tmp2;

	do {
		tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	} while (tmp != NULL);
}

void Singly_Linked_List::push_back(int data) {
	node* new_node = new node;
	new_node->next = NULL;
	new_node->data = data;

	if (list_size == 0) {
		tail = new_node;
		head = new_node;
		list_size++;
	}
	else {
		tail->next = new_node;
		tail = new_node;
		list_size++;
	}
}

void Singly_Linked_List::push_front(int data) {
	node* new_node = new node;
	new_node->next = NULL;
	new_node->data = data;

	if (list_size == 0) {
		tail = new_node;
		head = new_node;
		list_size++;
	}
	else {
		new_node->next = head;
		head = new_node;
		list_size++;
	}
}

void Singly_Linked_List::insert(int it, int data) {
	node* new_node = new node;
	new_node->next = NULL;
	new_node->data = data;

	node* tmp = head;
	for (int i = 0; i < it - 1; i++)
		tmp = tmp->next;
	
	new_node->next = tmp->next;
	tmp->next = new_node;

	list_size++;
}

void Singly_Linked_List::insert(int it, int* data, int len) {
	node* tmp = head;
	for (int i = 0; i < it - 1; i++)
		tmp = tmp->next;

	for (int i = 0; i < len; i++) {
		node* new_node = new node;
		new_node->data = data[i];
		new_node->next = tmp->next;
		tmp->next = new_node;
		tmp = tmp->next;
		list_size++;
	}
}

int Singly_Linked_List::front() {
	return head->data;
}

int Singly_Linked_List::back() {
	return tail->data;
}

void Singly_Linked_List::del(int it) {
	if (it < list_size && it > 0) {
		node* tmp = head;
		for (int i = 0; i < it - 1; i++)
			tmp = tmp->next;
		node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		list_size--;

		if (tail == NULL)
			tail = tmp;
	}
	else if (it == 0) {
		node* tmp = head;
		head = tmp->next;
		delete tmp;
		list_size--;
	}
}

void Singly_Linked_List::del(int it, int count) {
	if (it < list_size && it > 0) {
		node* tmp = head;
		for (int i = 0; i < it - 1; i++)
			tmp = tmp->next;
		for (int i = 0; i < count; i++) {
			node* tmp2 = tmp->next;
			if (tmp2 == NULL)
				break;
			tmp->next = tmp2->next;
			delete tmp2;
			list_size--;
		}
	}
	else if (it == 0) {
		for (int i = 0; i < count; i++) {
			node* tmp = head;
			if (tmp == NULL)
				break;
			head = tmp->next;
			delete tmp;
			list_size--;
		}
	}
}

int Singly_Linked_List::size() {
	return list_size;
}

void Singly_Linked_List::print() {
	node* tmp;
	tmp = head;

	do{
		cout << tmp->data << " ";
		tmp = tmp->next;
	} while (tmp != NULL);
	cout << "\n";
}

int main() {
	Singly_Linked_List s;
	s.push_back(1);
	s.push_back(2);
	int d[3] = { 4, 6, 5 };
	s.insert(1, d, 3);
	s.print();
}