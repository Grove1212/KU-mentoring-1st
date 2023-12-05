#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v, selected;
void select(int k) {
    if (k == 0) {
        for (auto item: selected) {
            cout << item << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        selected.push_back(v[i]);
        select(k - 1);
        selected.pop_back();
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    v.resize(N);

    for (auto &elem : v) cin >> elem;
    sort(v.begin(), v.end());

    select(M);
    return 0;
}