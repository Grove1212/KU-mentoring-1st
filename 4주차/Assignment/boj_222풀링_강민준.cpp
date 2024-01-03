#include <bits/stdc++.h>

using namespace std;
int N;

int solve(vector<vector<int>> board) {
    if (board.size() == 1) {
        return board[0][0];
    }

    int nSize = board.size() / 2;
    vector<vector<int>> nBoard(nSize, vector<int>(nSize));

    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < nSize; j++) {
            vector<int> temp;
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++) {
                    int y = i * 2 + k;
                    int x = j * 2 + m;
                    temp.push_back(board[y][x]);
                }
            }
            sort(temp.begin(), temp.end());
            nBoard[i][j] = temp[2];
        }
    }
    return solve(nBoard);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 크기는 1/2씩 줄어든다. 호출의 최대 깊이는 10
    // 메모리 문제 없을듯 (2^10 * 2^10 * 10 * 4byte) < 256mb
    cin >> N;
    vector <vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    cout << solve(v);
    return 0;
}