#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> selected;
vector<bool> isSelected;

void select(int k) {
    if (k == 0) {
        for (auto item : selected) {
            cout << item << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (isSelected[i]) continue;
        isSelected[i] = true;
        selected.push_back(i);
        select(k - 1);
        isSelected[i] = false;
        selected.pop_back();
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K;
    cin >> N >> K;
    isSelected.resize(N + 1, false);

    select(K);
    return 0;
}