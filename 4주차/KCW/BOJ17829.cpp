#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// v�� vector �ڷ����� �־��־�� ��
int map[1025][1025];
int second_big(int col, int row) {
	vector<int> v;
	v.push_back(map[col][row]);
	v.push_back(map[col + 1][row]);
	v.push_back(map[col][row + 1]);
	v.push_back(map[col + 1][row + 1]);
	sort(v.begin(), v.end());
	
	return v[2];
}

void divide(int N) {
	for (int i = 0; i < N; i += 2) {//row
		for (int j = 0; j < N; j += 2) {//col
			map[j/2][i/2] = second_big(j, i);
		}
	}
	if (N > 1) {
		N = N / 2;
		divide(N);
	}
}

int main() {
	int num;
	cin >> num;

	//map�� ���� �Է�
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> map[i][j];
		}
	}

	divide(num);

	cout << map[0][0];
}