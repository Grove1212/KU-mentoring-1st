#include <bits/stdc++.h>
using namespace std;
int N, board[1025][1025];
int secondMin(vector<int> v) {
    assert(v.size() == 4);
    sort(v.begin(), v.end());
    return v[1];
}
int select(pair<int,int> leftTop, int size) {
    // 기저 조건) 재귀의 끝부분에 해당한다. 더 이상 분기를 하지 않고 종료한다.
    if (size == 1) {
        return board[leftTop.first][leftTop.second];
    }

    // 현재 문제를 해결하는 phase
    // 4분할하여 부분문제에 대해서 정답을 리턴한다.
    // 최종적으로 root로 재귀가 돌아올 때, 이는 전체문제의 최적해를 나타낸다.
    int nSize = size / 2;
    // 2사분면
    int c2 = select(leftTop, nSize);
    // 1사분면
    int c1 = select({leftTop.first, leftTop.second + nSize}, nSize);
    // 3사분면
    int c3 = select({leftTop.first + nSize, leftTop.second}, nSize);
    // 4사분면
    int c4 = select({leftTop.first + nSize, leftTop.second + nSize}, nSize);

    return secondMin({c1, c2, c3, c4});
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 현재 문제를 해결하기 위한 상태를 명시적으로 기재한다.
    // 현재 문제는 (0, 0)을 좌측상단으로 삼는 size가 N인 정사각형이다.
    // (y, x)
    cout << select({0, 0}, N);
    return 0;
}