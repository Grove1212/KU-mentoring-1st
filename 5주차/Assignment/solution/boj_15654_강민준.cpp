#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v, selected;
vector<bool> isSelected;
void select(int k) {
    if (k == 0) {
        for (auto item: selected) {
            cout << item << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSelected[i]) continue;
        isSelected[i] = true;
        selected.push_back(v[i]);
        select(k - 1);
        selected.pop_back();
        isSelected[i] = false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    v.resize(N);
    isSelected.resize(M, false);

    for (auto &elem : v) cin >> elem;
    sort(v.begin(), v.end());
    select(M);
    return 0;
}