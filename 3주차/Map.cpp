#include <iostream>
#include <map>

using namespace std;
int main() {
    map<int, string> myMap;

    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    cout << "key2�� ����Ǿ� �ִ� ��: " << myMap[2] << endl;

    return 0;
}
