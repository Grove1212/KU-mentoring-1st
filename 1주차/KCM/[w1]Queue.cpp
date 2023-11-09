#include <iostream>
using namespace std;

class Queue {
private:
	typedef struct Node {
		int data;
		Node* next;
	} node;
	node* head;
	node* tail;
	int queue_size;
public:
	Queue();
	~Queue();

	void push(int data);
	int front();
	void pop();
	void print();
};

Queue::Queue() {
	head = NULL;
	tail = NULL;
	queue_size = 0;
}

Queue::~Queue() {
	node* tmp = head;
	node* tmp2;

	do {
		tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	} while (tmp != NULL);
}

void Queue::push(int data) {
	node* new_node = new node;
	new_node->next = NULL;
	new_node->data = data;

	if (queue_size == 0) {
		tail = new_node;
		head = new_node;
		queue_size++;
	}
	else {
		tail->next = new_node;
		tail = new_node;
		queue_size++;
	}
}

int Queue::front() {
	return head->data;
}

void Queue::pop() {
	if (queue_size > 0) {
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void Queue::print() {
	node* tmp;
	tmp = head;

	do {
		cout << tmp->data << " ";
		tmp = tmp->next;
	} while (tmp != NULL);
	cout << "\n";
}

int main() {
	Queue s;
	s.push(1);
	s.push(2);
	s.print();
	s.push(5);
	s.pop();
	s.print();
	cout << s.front() << "\n";
}