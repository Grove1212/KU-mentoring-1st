#include <iostream>
#include <map>

using namespace std;
int main() {
    map<int, string> myMap;

    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    cout << "key2에 저장되어 있는 값: " << myMap[2] << endl;

    return 0;
}
