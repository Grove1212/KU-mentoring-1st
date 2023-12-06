#include <iostream>
#include <vector>

using namespace std;

void generateSequences(int N, int M, int index, vector<int>& sequence) {
    // 기저 조건: 수열의 길이가 M이면 출력하고 종료
    if (sequence.size() == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    // 현재 선택한 숫자부터 N까지의 숫자를 고르도록 반복
    for (int i = index; i <= N; ++i) {
        sequence.push_back(i);  // 현재 숫자 추가
        generateSequences(N, M, i, sequence);
        sequence.pop_back();    // 현재 숫자 제거
    }
}

int main() {
    // 입력 받기
    int N, M;
    cin >> N >> M;

    // 수열을 저장할 벡터 초기화
    vector<int> sequence;

    // 재귀 함수 호출
    generateSequences(N, M, 1, sequence);

    return 0;
}
