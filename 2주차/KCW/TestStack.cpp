#include <iostream>
#include <stack>
using namespace std;

int main() {
	//스택 실험
	cout << "스택 실험\n";
	stack<int> stk;
	for (int i = 0; i < 15; i++) {
		stk.push(i);
	}

	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
}