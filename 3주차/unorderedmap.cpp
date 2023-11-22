#include <iostream>
#include <unordered_map>

using namespace std;
int main() {

    unordered_map<int, string> myHashMap;

    myHashMap[1] = "One";
    myHashMap[2] = "Two";
    myHashMap[3] = "Three";

    cout << "키2에 해당하는 값: " << myHashMap[2] << endl;

    if (myHashMap.find(4) != myHashMap.end()) {
        cout << "키4값이 존재합니다" << endl;
    }
    else {
        cout << "키4값이 없어요" << endl;
    }

    cout << "모든 키-값 출력:" << endl;
    for (const auto& pair : myHashMap) {
        cout << "키: " << pair.first << ", 값: " << pair.second << endl;
    }

    return 0;
}
