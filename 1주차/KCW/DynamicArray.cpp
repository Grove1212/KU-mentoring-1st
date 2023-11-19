#include <iostream>
#include <cstring>
using namespace std;

class DynamicArray {
	int arrSize;
	int index;
	char* p;
public:
	DynamicArray();
	~DynamicArray();
	void push_back(char* c);
	char pop_back();
	void insert(int idx, char* c);
	void Delete(int idx); // delete는 식별자로 사용 불가능
	char at(int idx);
	int size();
	void clear();
	void print();
};

DynamicArray::DynamicArray() {
		arrSize = 2;
		index = -1;
		p = new char[arrSize];
}
DynamicArray::~DynamicArray() {
	delete p;
}
void DynamicArray::push_back(char* c) {
	int oldindex = index + 1; // 구 인덱스
	index += strlen(c); // 바뀐 인덱스
	if (arrSize < index + 1) { // 동적으로 새로 할당해줘야하는지 아닌지 판단
		arrSize = (index) * 2;
		char* tmp = new char[arrSize];
		for (int i = 0; i < oldindex; i++) {
			tmp[i] = p[i];
		}
		delete p;
		p = tmp;
	}
	int j = 0;
	for (int i = oldindex; i <= index; i++) {
		p[i] = c[j];
		j++;
	}
}
char DynamicArray::pop_back() {
	p[index] = ' ';
	index = index - 1;
	return p[index + 1];
}
void DynamicArray::insert(int idx, char* c) {
	if (arrSize < idx + strlen(c)) {
		arrSize = (idx + strlen(c)) * 2;
		char* tmp = new char[arrSize];
		int j = 0;
		for (int i = 0; i <= index; i++) {
			if (i == idx)
				j += strlen(c);
			tmp[j] = p[i];
			j++;
		}
		delete p;
		p = tmp;
	}
	index += strlen(c);
	int j = 0;
	for (int i = idx; i < index; i++) {
		p[i] = c[j];
		j++;
	}
}
void DynamicArray::Delete(int idx) {
	for (int i = index - idx + 1; i < index; i++) {
		p[i] = p[i + 1];
	}
}
char DynamicArray::at(int idx) {
	return p[idx];
}
int DynamicArray::size() { return arrSize; }
void DynamicArray::clear() {
	index = -1;
	arrSize = 1;
	delete p;
	p = NULL;
}
void DynamicArray::print() {
	for (int i = 0; i < index; i++)
		cout << "p[ " << i << " ] = " << p[i] << endl;
}



int main() {
	DynamicArray arr;
	char a[] = "abc";
	char b[] = "def";
	arr.push_back(a);
	arr.push_back(b);
	arr.print();
}