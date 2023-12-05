#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v, selected;
vector<bool> isSelected;
void select(int offset, int k) {
    if (k == 0) {
        for (auto item: selected) {
            cout << item << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = offset; i < N; i++) {
        if (isSelected[i]) continue;
        isSelected[i] = true;
        selected.push_back(v[i]);
        select(i + 1, k - 1);
        selected.pop_back();
        isSelected[i] = false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    isSelected.resize(N, false);
    v.resize(N);
    for (auto &elem : v) cin >> elem;

    sort(v.begin(), v.end());

    select(0, M);
    return 0;
}