#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    int moves = 0;

    for (int i = 0; i < M; ++i) {
        int target;
        cin >> target;

        int idx = 0;

        while (dq[idx] != target) {
            idx++;
        }

        // �տ��� ���� �� ���� ��
        if (idx <= dq.size() / 2) {
            while (dq.front() != target) {
                dq.push_back(dq.front());
                dq.pop_front();
                moves++;
            }
        }
        else { // �ڿ��� ���� �� ���� ��
            while (dq.front() != target) {
                dq.push_front(dq.back());
                dq.pop_back();
                moves++;
            }
        }

        dq.pop_front();
    }

    cout << moves << endl;

    return 0;
}
