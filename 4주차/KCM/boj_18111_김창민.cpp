#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x, y, block;
	int max = -1;
	int min = 257;
	vector<vector<int>> land;
	vector<int> v;
	int h;
	int minTime = 1000000000;
	int maxHeight = -1;
	int time;
	int tmpBlock;
	int i, j, k;

	cin >> y >> x >> block;

	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			cin >> h;
			v.push_back(h);

			if (min > h)
				min = h;
			if (max < h)
				max = h;
		}
		land.push_back(v);
		v.clear();
	}

	for (k = min; k <= max; k++) {
		time = 0;
		tmpBlock = block;

		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				h = land[i][j] - k;

				if (h > 0) {
					time += h * 2;
					tmpBlock += h;
				}
				else if (h < 0) {
					time += -h;
					tmpBlock += h;
				}
			}
		}

		if (minTime > time && tmpBlock >= 0) {
			minTime = time;
			maxHeight = k;
		}
		else if (minTime == time && tmpBlock >= 0) {
			if (k > maxHeight)
				maxHeight = k;
		}
	}

	cout << minTime << ' ' << maxHeight;
}