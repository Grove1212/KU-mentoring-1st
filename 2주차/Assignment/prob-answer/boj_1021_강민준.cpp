#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N, M;
    cin >> N >> M;

    // 양방향 삽입,삭제시 유용
    deque<int> dq(N);

    for(int i=0; i < N; i++){
        dq[i] = i + 1;
    }

    vector<int> toSelect(M);
    for(int i = 0; i < M; i++){
        cin >> toSelect[i];
    }

    int cnt = 0;
    for(int i = 0; i < M; i++){
        int idx = 0;
        for(int k = idx; k < dq.size(); k++){
            if(dq[k] == toSelect[i]){
                idx = k;
                break;
            }
        }
        // 뽑고자하는 원소가 있는 위치 : idx
        while(true) {
            if (dq[idx] == dq.front()) {
                dq.pop_front();
                break;
            }
            if (idx <= dq.size() - idx) {
                int element = dq.front();
                dq.pop_front();
                dq.push_back(element);
                idx--;
            }
            else{
                int element = dq.back();
                dq.pop_back();
                dq.push_front(element);
                idx = (idx + 1) % dq.size();
            }
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}