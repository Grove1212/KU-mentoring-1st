#include <bits/stdc++.h>
using namespace std;

void prt_postfix(const vector<int>& v, int left, int right) {
    if (left > right) return;
    int rootIdx = left;
    int k = rootIdx + 1;
    while (k <= right && v[k] < v[rootIdx]) k++;
    // v[rootIdx] <= v[k] 인 최초의 k가 right의 offset이된다.
//    cout << "left: " << left << ", right: " << right
//         << ", k: " << k << "\n";
    prt_postfix(v, left + 1, k - 1);
    prt_postfix(v, k, right);
    cout << v[rootIdx] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    freopen("input.txt", "r", stdin);

    vector<int> v;
    int in;
    while (cin >> in) {
        v.push_back(in);
    }

    prt_postfix(v, 0, v.size() - 1);
    return 0;
}