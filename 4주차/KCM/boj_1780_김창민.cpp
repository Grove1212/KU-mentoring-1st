#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
int result[3] = { 0, 0, 0 }; // -1, 0, 1의 개수 저장

void checkFull(int, int, int);

int main() {
	int N; // 1 <= N <= 3^7, N = 3^n
	int val;
	int i, j;

	cin >> N;

	vector<int> v;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> val;
			v.push_back(val);
		}
		matrix.push_back(v);
		v.clear();
	}

	checkFull(0, 0, N);

	cout << result[0] << "\n" << result[1] << "\n" << result[2];
}

void checkFull(int x, int y, int n) {
	bool isFull = true; // 숫자가 모두 같은지 체크하는 변수
	int start = matrix[x][y]; // 시작점의 숫자 확인
	
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (matrix[i][j] != start) {
				isFull = false;
				break;
			}
		}
		if (!isFull)
			break;
	}

	if (isFull) { // 전체가 같은 숫자면 종이 개수 증가
		result[start + 1] += 1;
	}
	else { // 그렇지 않으면 종이 9등분 후 확인
		checkFull(x, y, n / 3);
		checkFull(x + n / 3, y, n / 3);
		checkFull(x + n / 3 * 2, y, n / 3);
		checkFull(x, y + n / 3, n / 3);
		checkFull(x + n / 3, y + n / 3, n / 3);
		checkFull(x + n / 3 * 2, y + n / 3, n / 3);
		checkFull(x, y + n / 3 * 2, n / 3);
		checkFull(x + n / 3, y + n / 3 * 2, n / 3);
		checkFull(x + n / 3 * 2, y + n / 3 * 2, n / 3);
	}

}