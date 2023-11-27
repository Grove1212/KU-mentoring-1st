#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

// sol1. balanced binary search tree 활용
    // set<int> existSet;
    // for (int i = 0; i < N; i++) {
    //     int item;
    //     cin >> item;
    //     existSet.insert(item);
    // }

    // for (auto elem : existSet) {
    //     cout << elem << '\n';
    // }

    bool count[2000002] = {false};
    for (int i = 0; i < N; i++) {
        int item;
        cin >> item;
        // 0 -> 1000000
        // 1 -> 1000001
        // -1 -> 1000000 - 1
        count[item + 1000000] = true;
    }
    for (int i = 0; i <= 2000000; i++) {
        if (count[i]) cout << i - 1000000 << '\n';
    }

    return 0;
}