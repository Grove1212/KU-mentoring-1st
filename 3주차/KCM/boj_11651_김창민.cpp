#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};

bool compare(Point A, Point B) {
	if (A.y == B.y) {
		return A.x < B.x;
	}
	else {
		return A.y < B.y;
	}
}

int main() {
	int N;
	Point tmp;

	cin >> N;
	vector <Point>p;

	for (int i = 0; i < N; i++) {
		cin >> tmp.x >> tmp.y;
		p.push_back(tmp);
	}

	sort(p.begin(), p.end(), compare);

	for (int i = 0; i < N; i++)
		cout << p[i].x << ' ' << p[i].y << "\n";
}