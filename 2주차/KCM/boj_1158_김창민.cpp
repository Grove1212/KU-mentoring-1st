#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue <int>q;
	int N, K;
	int tmp;
	int it;

	cin >> N >> K;
	
	for (int i = 0; i < N; i++)
		q.push(i + 1);

	cout << '<';
	it = 0;
	while (!q.empty()) {
		it++;
		tmp = q.front();
		q.pop();

		if (it < K) {
			q.push(tmp);
		}
		else {
			if (!q.empty()) {
				cout << tmp << ", ";
			}
			else {
				cout << tmp << '>';
			}
			it = 0;
		}
	}
}