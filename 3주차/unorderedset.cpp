#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_set<int> myHashSet;

    myHashSet.insert(1);
    myHashSet.insert(2);
    myHashSet.insert(3);

    if (myHashSet.find(2) != myHashSet.end()) {
        cout << "키2값이 있다" << endl;
    }
    else {
        cout << "2값이 없다" << endl;
    }

    cout << "해쉬 셋에 있는 모든 값:" << endl;
    for (const auto& value : myHashSet) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
