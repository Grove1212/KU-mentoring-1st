#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N;
  cin >> N;
  while (N--) {
    string input;
    cin >> input;
    stack<char> stk;
    for (auto c : input) {
      if (!stk.empty() && stk.top() == '(' && c == ')')
        stk.pop();
      else
        stk.push(c);
    }
    string ans = stk.empty() ? "YES" : "NO";
    cout << ans << '\n';
  }

  return 0;
}