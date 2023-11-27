#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // bst 기반
    set<int> s1, s2;

    int na, nb;
    cin >> na >> nb;

    for (int i = 0; i < na; i++) {
        int elem;
        cin >> elem;
        s1.insert(elem);
    }

    for (int i = 0; i < nb; i++) {
        int elem;
        cin >> elem;
        s2.insert(elem);
    }

    vector<int> answer;
    for (const auto &item: s1) {
        // s2에서 item을 찾지 못할 경우
        if (s2.find(item) == s2.end()) {
            answer.push_back(item);
        }
    }

    cout << answer.size() << '\n';
    for (const auto &item: answer) {
        cout << item << ' ';
    }

    return 0;
}