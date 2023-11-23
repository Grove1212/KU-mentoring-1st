#include <iostream>
//#include <deque>
#include <queue>
using namespace std;

int main() {
	//deque <int>dq;
	queue <int>q;

	int N, M;
	int loc;
	int result = 0;
	int mov;

	cin >> N >> M;

	/*
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	*/

	for (int i = 1; i <= N; i++)
		q.push(i);

	for (int i = 0; i < M; i++) {
		cin >> loc;

		if (loc == q.front()) {
			q.pop();
		}
		else {
			mov = 0;
			while (loc != q.front()) {
				q.push(q.front());
				q.pop();
				mov++;
			}
			q.pop();

			if (mov > q.size() / 2)
				mov = q.size() - mov + 1;
			result += mov;
		}
	}

	cout << result;
}