#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int num;
	cin >> num;
	int* p = new int[num];
	for (int i = 0; i < num; i++)
		cin >> p[i];
	sort(p, p + num);

	int* compare = new int[num];
	for (int i = 0; i < num; i++)
	{
		compare[i] = p[i] * (num - i);//ºñ±³
	}
	sort(compare, compare + num);
	cout << compare[num - 1];
}
//ex) 10,8,7,5,2