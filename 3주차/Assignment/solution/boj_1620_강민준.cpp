#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // bst 사용 => 문자열의 길이가 어느 정도 길 경우, hashing에 들어가는 상수 시간이 더 클 수 있음
    map<string, int> mp;
    map<int, string> revMap;

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string in;
        cin >> in;
        mp[in] = i;
        revMap[i] = in;
    }

    for (int i = 0; i < M; i++) {
        string q;
        cin >> q;
        // 포켓몬의 이름은 모두 영문자로 이루어져있다.
        if (('a' <= q[0] && q[0] <= 'z') || ('A' <= q[0] && q[0] <= 'Z')) {
            cout << mp[q] << '\n';
        } else {
            cout << revMap[stoi(q)] << '\n';
        }
    }

    return 0;
}