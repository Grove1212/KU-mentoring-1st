#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> fib;
class Fibonacci {
public:
	Fibonacci() {
		pair<int, int> p;

		p = make_pair(1, 0);
		fib.push_back(p);
		p = make_pair(0, 1);
		fib.push_back(p);
	}
	void getFib(int n);
	void printFib(int n);
};

void Fibonacci::getFib(int n) {
	pair<int, int> p;

	if (n >= fib.size()) {
		getFib(n - 2);
		getFib(n - 1);
		
		p = make_pair(fib[n - 2].first + fib[n - 1].first, fib[n - 2].second + fib[n - 1].second);
		fib.push_back(p);
	}
}

void Fibonacci::printFib(int n) {
	getFib(n);
	cout << fib[n].first << ' ' << fib[n].second << "\n";
}

int main() {
	int testCase, n;
	Fibonacci f;

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;

		f.printFib(n);
	}
}