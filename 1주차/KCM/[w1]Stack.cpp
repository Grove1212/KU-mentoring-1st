#include <iostream>
using namespace std;

class Stack {
private:
	typedef struct Node {
		int data;
		Node* next;
	} node;
	node* head;
	int stack_size;
public:
	Stack();
	~Stack();

	void push(int data);
	int top();
	void pop();
	void print();
};

Stack::Stack() {
	head = NULL;
	stack_size = 0;
}

Stack::~Stack() {
	node* tmp = head;
	node* tmp2;

	do {
		tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	} while (tmp != NULL);
}

void Stack::push(int data) {
	node* new_node = new node;
	new_node->next = head;
	new_node->data = data;
	head = new_node;
	stack_size++;
}

int Stack::top() {
	return head->data;
}

void Stack::pop() {
	if (stack_size > 0) {
		node* tmp = head;
		head = head->next;
		delete tmp;
		stack_size--;
	}
}

void Stack::print() {
	node* tmp;
	tmp = head;

	do {
		cout << tmp->data << " ";
		tmp = tmp->next;
	} while (tmp != NULL);
	cout << "\n";
}

int main() {
	Stack s;

	s.push(1);
	s.push(2);
	s.push(4);
	s.print();
	cout << s.top() << "\n";
	s.pop();
	s.pop();
	s.print();
}