#include <bits/stdc++.h>
using namespace std;
void preorder(char adj[][3], int cur) {
    cout << adj[cur][0];
    for (int i = 1; i < 3; i++) {
        if (adj[cur][i] != '.') {
            preorder(adj, adj[cur][i] - 'A');
        }
    }
}
void inorder(char adj[][3], int cur) {
    if (adj[cur][1] != '.')
        inorder(adj, adj[cur][1] - 'A');
    cout << adj[cur][0];
    if (adj[cur][2] != '.')
        inorder(adj, adj[cur][2] - 'A');
}
void postorder(char adj[][3], int cur) {
    for (int i = 1; i < 3; i++) {
        if (adj[cur][i] != '.') {
            postorder(adj, adj[cur][i] - 'A');
        }
    }
    cout << adj[cur][0];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    char adj[27][3];
    for (int i = 0; i < N; i++) {
        char a, l, r;
        cin >> a >> l >> r;
        adj[a - 'A'][0] = a;
        adj[a - 'A'][1] = l;
        adj[a - 'A'][2] = r;
    }

    preorder(adj, 0);
    cout << "\n";
    inorder(adj, 0);
    cout << "\n";
    postorder(adj, 0);

    return 0;
}