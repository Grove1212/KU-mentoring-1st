#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str = "";
	stack<char> bracket;
	char c;
	int i;
	bool isBalanced;

	while (true) {
		getline(cin, str);
		if (str == ".")
			break;
		
		isBalanced = true;
		i = 0;
		while (str[i] != '.') {
			if (str[i] == '(' || str[i] == '[') {
				bracket.push(str[i]);
			}
			else if (str[i] == ')') {
				if (bracket.empty()) {
					isBalanced = false;
					break;
				}
				else if (bracket.top() == '(') {
					bracket.pop();
				}
				else if (bracket.top() != '(') {
					isBalanced = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (bracket.empty()) {
					isBalanced = false;
					break;
				}
				else if (bracket.top() == '[') {
					bracket.pop();
				}
				else if (bracket.top() != '[') {
					isBalanced = false;
					break;
				}
			}
			i++;
		}

		if (bracket.empty() && isBalanced) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

		if (!bracket.empty()) {
			while (!bracket.empty())
				bracket.pop();
		}
	}
}