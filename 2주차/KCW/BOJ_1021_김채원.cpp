//���� �̿��� ���� Ǯ��
//while���� �̿��� �� ���������� ����ϴ� ����� �����.
//dq�� vector�� �����ϴٴ� ���� �˾Ұ� �׷����� index�� �ű� �� �ִٴ� ���� �˾Ҵ�.
//dq�� ����Լ� size, pop front, pop back ���� ������ ������ �� �־���.
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;//���� ũ��, �̾Ƴ����� ���� ����

	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int offset;
	int idx = 0;
	int count = 0;
	while (M--) {
		cin >> offset;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == offset)
				idx = i;
		}

		if (idx <= (dq.size() - idx)) {
			while (true) {
				if (dq.front() == offset) {
					dq.pop_front();
					break;
				}
				count++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (true) {
				if (dq.front() == offset) {
					dq.pop_front();
					break;
				}
				count++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}

	}
	cout << count;
	return 0;
}