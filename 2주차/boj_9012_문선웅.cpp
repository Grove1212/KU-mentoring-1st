#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool isVPS(const string& s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch); 
        }
        else if (ch == ')') {
            if (st.empty() || st.top() != '(') {
                return false; 
            }
            st.pop();
        }
    }

    return st.empty(); 
}

int main() {
    int n; 
    cin >> n;
    queue<string>q;

    for (int i = 0; i < n;i++) {
        string input;
        cin >> input;
        q.push(input);
    }

    for (int i = 0; i < n; i++) {
        string input;
        input = q.front();
        if (isVPS(input)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        q.pop();
    }


    return 0;
}
