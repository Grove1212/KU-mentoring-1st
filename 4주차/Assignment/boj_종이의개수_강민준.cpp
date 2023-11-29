#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
int N, board[2501][2501];
bool isAllSame(pair<int, int> offset, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[offset.first + i][offset.second + j] !=
                board[offset.first][offset.second])
                return false;
        }
    }
    return true;
}
tp solve(pair<int,int> offset, int size) {
    if (isAllSame(offset, size)) {
        switch (board[offset.first][offset.second]) {
            case -1:
                return make_tuple(1, 0, 0);
            case 0:
                return make_tuple(0, 1, 0);
            case 1:
                return make_tuple(0, 0, 1);
            default:
                assert(0);
        }
    }
    int nSize = size / 3;
    tp result = make_tuple(0, 0, 0);
    auto &[f, s, t] = result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pair<int,int> nOffset = {offset.first + i * nSize, offset.second + j * nSize};
            tp subResult = solve(nOffset, nSize);
            f += get<0>(subResult), s += get<1>(subResult), t += get<2>(subResult);
        }
    }
    return result;
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

    auto[f, s, t] = solve({0, 0}, N);
    cout << f << ' ' << s << ' ' << t;
    return 0;
}