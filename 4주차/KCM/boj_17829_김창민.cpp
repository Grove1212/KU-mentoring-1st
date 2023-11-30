#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> matrix;

int checkSecond(int, int);
void pooling(int);

int main() {
	int N, val;

	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> val;
			v.push_back(val);
		}
		matrix.push_back(v);
		v.clear();
	}

	pooling(N);
	cout << matrix[0][0];
}

int checkSecond(int x, int y) {
	int arr[4];
	arr[0] = matrix[y][x];
	arr[1] = matrix[y][x + 1];
	arr[2] = matrix[y + 1][x];
	arr[3] = matrix[y + 1][x + 1];

	sort(arr, arr + 4);

	return arr[2];
}

void pooling(int size) {
	if (size > 1) {
		for (int i = 0; i < size / 2; i++)
			for (int j = 0; j < size / 2; j++)
				matrix[i][j] = checkSecond(j * 2, i * 2);

		pooling(size / 2);
	}
}