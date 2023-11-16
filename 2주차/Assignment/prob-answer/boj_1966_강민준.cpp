#include <bits/stdc++.h>
using namespace std;
bool check(int priorities[], int idx) {
  for (int i = 0; i < 101; i++) {
    if (i != idx && priorities[idx] < priorities[i])
      return false;
  }
  return true;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    // 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 뒤에 배치
    int N, priorities[101] = {0}, M;
    cin >> N >> M;

    queue<int> q; // 초기 문서의 index가 들어간다.
    int counter = 1;
    for (int i = 0; i < N; i++) {
      cin >> priorities[i];
      q.push(i);
    }

    int ans = -1;
    while (!q.empty()) {
      // priorities[q.top()]보다 중요도가 높은 문서가 존재 X일 경우 pop
      if (check(priorities, q.front())) {
        if (q.front() == M) {
          ans = counter;
          break;
        }
        
        priorities[q.front()] = 0;
        q.pop();
        counter++;
      }
      else {
        int fr = q.front();
        q.pop();
        q.push(fr);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}