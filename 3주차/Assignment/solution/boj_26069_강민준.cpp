#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    set<string> dance;
    dance.insert("ChongChong");

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        if (dance.find(a) != dance.end() || dance.find(b) != dance.end()) {
            dance.insert(a);
            dance.insert(b);
        }
    }
    cout << dance.size();
    return 0;
}