#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(int N, int M, vector<int>& numbers, vector<bool>& used, vector<int>& permutation) {
    // 기저 조건: 수열의 길이가 M이면 출력하고 종료
    if (permutation.size() == M) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    // 중복되지 않는 수열을 구해야 하므로 used 배열을 사용하여 중복을 방지
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            used[i] = true;                // 숫자 사용 표시
            permutation.push_back(numbers[i]);  // 현재 숫자 추가
            generatePermutations(N, M, numbers, used, permutation);  // 재귀 호출
            used[i] = false;               // 숫자 사용 취소
            permutation.pop_back();        // 현재 숫자 제거
        }
    }
}

int main() {
    // 입력 받기
    int N, M;
    cin >> N >> M;

    // N개의 수 입력 받기
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 입력 받은 수열을 사전 순으로 정렬
    sort(numbers.begin(), numbers.end());

    // 사용 여부를 나타내는 배열 초기화
    vector<bool> used(N, false);

    // 순열을 저장할 벡터 초기화
    vector<int> permutation;

    // 재귀 함수 호출
    generatePermutations(N, M, numbers, used, permutation);

    return 0;
}
