#include <iostream>
#include <queue>
using namespace std;

int main() {
	//큐 실험
	cout << "큐 실험\n";
	queue<int> que;
	for (int i = 0; i < 15; i++) {
		que.push(i);
	}

	while (!que.empty()) {
		cout << que.front() << endl;
		que.pop();
	}

	return 0;
}