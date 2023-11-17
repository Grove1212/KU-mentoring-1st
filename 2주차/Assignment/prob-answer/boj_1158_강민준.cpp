#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  int turn = 1, removed = 0;
  vector<int> ans;
  queue<int> q;
  for (int i = 1; i <= N; i++) q.push(i);

  while (removed < N) {
    // simulate => pop front then, push back if not Kth element
    while (turn < K) {
      int fr = q.front();
      q.pop();
      q.push(fr);
      turn++;
    }
    turn = 1;
    ans.push_back(q.front()); q.pop();
    removed++;
  }

  if (ans.size() == 1) {
    cout << "<" << ans[0] << ">";
  } else {
    cout << "<" << ans[0] << ", ";
    for (int i = 1; i < N - 1; i++) {
      cout << ans[i] << ", ";
    }
    cout << ans.back() << ">";
  }
  
  return 0;
}