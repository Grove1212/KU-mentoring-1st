#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  stack<int> stk;
  int K;
  cin >> K;
  
  long long sum = 0L;
  while (K--) {
    int input;
    cin >> input;

    if (input == 0) {
      if (!stk.empty()) {
        sum -= stk.top();
        stk.pop();
      }
    } else {
      sum += input;
      stk.push(input);
    }
  }
  cout << sum;
  return 0;
}