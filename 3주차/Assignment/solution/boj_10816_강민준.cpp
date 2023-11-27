#include <bits/stdc++.h>

using namespace std;
/** [w3] 풀이 <br/>
 * 최대 5*10^6 개의 입력 <br/>
 * 최대 5*10^6 개의 쿼리 => M <br/>
 * M개의 쿼리를 시간 제한 1초안에 처리하기 위해서 O(logN) 이하의 복잡도를 가지도록 탐색 알고리즘 설계 <br/>
 * @result O(M)의 시간복잡도
 */
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    unordered_map<int, int> hashMap;
    for (int i = 0; i < N; i++) {
        int item;
        cin >> item;
        hashMap[item] += 1;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        cout << hashMap[k] << ' ';
    }

    return 0;
}