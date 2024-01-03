#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(int N, int M, vector<int>& permutation, vector<bool>& used) {
    // 기저 조건: 수열의 길이가 M이면 출력하고 종료
    if (permutation.size() == M) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    // 1부터 N까지의 숫자 중에서 아직 사용되지 않은 숫자를 찾아 재귀 호출
    for (int i = 1; i <= N; ++i) {
        if (!used[i]) {
            used[i] = true;         // 숫자 사용 표시
            permutation.push_back(i);  // 현재 숫자 추가
            generatePermutations(N, M, permutation, used);  // 재귀 호출
            used[i] = false;        // 숫자 사용 취소
            permutation.pop_back(); // 현재 숫자 제거
        }
    }
}

int main() {
    // 입력 받기
    int N, M;
    cin >> N >> M;

    // 사용 여부를 나타내는 배열 초기화
    vector<bool> used(N + 1, false);

    // 순열을 저장할 벡터 초기화
    vector<int> permutation;

    // 재귀 함수 호출
    generatePermutations(N, M, permutation, used);

    return 0;
}
