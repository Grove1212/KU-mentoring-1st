#include <iostream>
#include <unordered_map>

using namespace std;
int main() {

    unordered_map<int, string> myHashMap;

    myHashMap[1] = "One";
    myHashMap[2] = "Two";
    myHashMap[3] = "Three";

    cout << "Ű2�� �ش��ϴ� ��: " << myHashMap[2] << endl;

    if (myHashMap.find(4) != myHashMap.end()) {
        cout << "Ű4���� �����մϴ�" << endl;
    }
    else {
        cout << "Ű4���� �����" << endl;
    }

    cout << "��� Ű-�� ���:" << endl;
    for (const auto& pair : myHashMap) {
        cout << "Ű: " << pair.first << ", ��: " << pair.second << endl;
    }

    return 0;
}
