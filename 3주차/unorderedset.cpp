#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_set<int> myHashSet;

    myHashSet.insert(1);
    myHashSet.insert(2);
    myHashSet.insert(3);

    if (myHashSet.find(2) != myHashSet.end()) {
        cout << "Ű2���� �ִ�" << endl;
    }
    else {
        cout << "2���� ����" << endl;
    }

    cout << "�ؽ� �¿� �ִ� ��� ��:" << endl;
    for (const auto& value : myHashSet) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
