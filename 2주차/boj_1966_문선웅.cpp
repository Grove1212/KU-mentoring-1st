#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; 
    queue<int> answer;

    while (t--) {
        int n, m;
        cin >> n >> m; 
        queue<pair<int, int>> q; 
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            q.push({ priority, i });
            pq.push(priority);
        }

        int cnt = 0;

        while (!q.empty()) {
            int curPriority = q.front().first;
            int curPosition = q.front().second;
            q.pop();

            if (curPriority == pq.top()) {
                pq.pop();
                cnt++;

                if (curPosition == m) {
                    answer.push(cnt);
                    break;
                }
            }
            else {
                q.push({ curPriority, curPosition });
            }
        }
    }

    while (!answer.empty())
    {
        cout << answer.front() << endl;
        answer.pop();
    }
    return 0;
}
