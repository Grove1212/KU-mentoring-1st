#include <iostream>
using namespace std;

class Dynamic_array {
private:
	int* arr;
	int d_size;
	int d_used;
	
	void double_size();
	void half_size();
public:
	Dynamic_array();
	Dynamic_array(int n);
	~Dynamic_array();
	
	void push_back(int data);
	void pop_back();
	void insert(int index, int data);
	void del(int index);
	int at(int index);
	int size();
	void clear();
	void print();
};

Dynamic_array::Dynamic_array() {
	this->d_size = 1;
	this->arr = new int[this->d_size];
	this->d_used = 0;
}

Dynamic_array::Dynamic_array(int n) {
	this->d_size = n;
	this->arr = new int[this->d_size];
	this->d_used = 0;
}

Dynamic_array::~Dynamic_array() {
	delete[] this->arr;
}

void Dynamic_array::double_size() {
	int* tmp = new int[this->d_size];
	for (int i = 0; i < this->d_size; i++)
		tmp[i] = this->arr[i];
	delete[] this->arr;

	this->d_size *= 2;
	arr = new int[this->d_size];
	for (int i = 0; i < this->d_size / 2; i++)
		arr[i] = tmp[i];
	delete[] tmp;
}

void Dynamic_array::half_size() {
	int* tmp = new int[this->d_size];
	for (int i = 0; i < this->d_size; i++)
		tmp[i] = this->arr[i];
	delete[] this->arr;

	this->d_size /= 2;
	arr = new int[this->d_size];
	for (int i = 0; i < this->d_size; i++)
		arr[i] = tmp[i];
	delete[] tmp;
}

void Dynamic_array::push_back(int data) {
	if (this->d_size <= this->d_used)
		this->double_size();
	this->arr[this->d_used] = data;
	this->d_used++;
}

void Dynamic_array::pop_back() {
	if (this->d_used > 0)
		this->d_used--;

	if (this->d_used <= this->d_size / 2)
		this->half_size();
}

void Dynamic_array::insert(int index, int data) {
	if (index < this->d_used && index >= 0) {
		if (this->d_size <= this->d_used)
			this->double_size();

		for (int i = this->d_used; i > index; i--)
			this->arr[i] = this->arr[i - 1];
		this->arr[index] = data;
		this->d_used++;
	}
}

void Dynamic_array::del(int index) {
	if (this->d_used > 0) {
		if (index >= 0 && index < this->d_used) {
			for (int i = index; i < this->d_used - 1; i++)
				this->arr[i] = this->arr[i + 1];
			this->d_used--;

			if (this->d_used <= this->d_size / 2)
				this->half_size();
		}
	}
}

int Dynamic_array::at(int index) {
	if (index >= 0 && index < this->d_used)
		return this->arr[index];
	else
		return -1;
}

int Dynamic_array::size() {
	return this->d_size;
}

void Dynamic_array::clear() {
	delete[] this->arr;
	this->d_used = 0;
	this->d_size = 1;
	this->arr = new int[this->d_size];
}

void Dynamic_array::print() {
	for (int i = 0; i < d_used; i++)
		cout << arr[i] << ' ';
	cout << "\n";
}

int main() {
	Dynamic_array d;
	string command;
	int n, i;

	do {
		cin >> command;
		if (command == "push") {
			cin >> n;
			d.push_back(n);
		}
		else if (command == "pop") {
			d.pop_back();
		}
		else if (command == "insert") {
			cin >> i >> n;
			d.insert(i, n);
		}
		else if (command == "delete") {
			cin >> i;
			d.del(i);
		}
		else if (command == "at") {
			cin >> i;
			cout << d.at(i) << "\n";
		}
		else if (command == "size") {
			cout << d.size() << "\n";
		}
		else if (command == "clear") {
			d.clear();
		}
		else if (command == "print") {
			d.print();
		}
	} while (command != "0");
}