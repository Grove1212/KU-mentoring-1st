#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	const float trimmed_mean = 0.15;
	int sum = 0;
	int mean = 0;
	int n;

	cin >> n;

	if (n != 0) {
		int mean_n = n;
		int* level = new int[n];
		int	trim = n * trimmed_mean + 0.5;


		for (int i = 0; i < n; i++) {
			cin >> level[i];
			sum += level[i];
		}

		sort(level, level + n);

		for (int i = 0; i < trim; i++) {
			sum -= level[i];
			sum -= level[n - i - 1];
			mean_n -= 2;
		}

		mean = (float)sum / mean_n + 0.5;

		cout << mean;

		delete[] level;
	}
	else {
		cout << '0';
	}
}