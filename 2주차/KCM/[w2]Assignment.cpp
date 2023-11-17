#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {
	ifstream in;
	in.open("input.txt");

	ofstream out;
	out.open("output.txt");
	
	stack <int>s;
	queue <int>q;
	deque <int>dq1;
	deque <int>dq2;

	int dsize;
	int data;

	in >> dsize;
	int* arr = new int[dsize];
	
	for (int i = 0; i < dsize; i++) {
		in >> data;
		s.push(data);
		q.push(data);
		dq1.push_back(data);
		dq2.push_back(data);
		arr[i] = data;
	}

	out << "Stack\n"; //Stack
	for (int i = 0; i < dsize; i++) {
		out << s.top() << ' ';
		s.pop();
	}
	out << "\n\n";

	out << "Queue\n"; //Queue
	for (int i = 0; i < dsize; i++) {
		out << q.front() << ' ';
		q.pop();
	}
	out << "\n\n";

	out << "Dueue -> Stack\n"; //Deque
	for (int i = 0; i < dsize; i++) {
		out << dq1.back() << ' ';
		dq1.pop_back();
	}
	out << "\n\n";

	dq1 = dq2;
	out << "Dueue -> Queue\n";
	for (int i = 0; i < dsize; i++) {
		out << dq1.front() << ' ';
		dq1.pop_front();
	}
	out << "\n\n";

	out << "Array\n";
	for (int i = 0; i < dsize; i++)
		out << arr[i] << ' ';
	out << "\n\n";

	delete[] arr;
	in.close();
	out.close();
}
