#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> selected;
void select(int k) {
    if (k == 0) {
        for (auto item: selected) {
            cout << item << ' ';
        }
        cout << '\n';
        return;
    }
    int offset = selected.empty() ? 1 : selected.back();
    for (int i = offset; i <= N; i++) {
        selected.push_back(i);
        select(k - 1);
        selected.pop_back();
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    select(M);

    return 0;
}