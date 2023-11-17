#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;

	while(T>0) {//T���� ���ڿ��� VPS ���� �Ǵ�
		T--;
		string s;
		cin >> s;
		stack<char> PS;

		string answer = "YES";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')//(�� ������ �ֱ�
				PS.push(s[i]);
			else if (!PS.empty() && PS.top() == '(' && s[i] == ')') {
				PS.pop();// pop�� ������ ������ ����
			}
			else { // ���� �������� ���� no
				answer = "NO";
				break;
			}
		}
		if (!PS.empty()) //(�� ���� pop �������� ��� not VPS
			answer = "NO";

		cout << answer << endl;
	}
	return 0;
}