#include <iostream>
#include <set>

using namespace std;
int main() {
    set<int> mySet;

    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);

    for (const auto& value : mySet) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
