#include <iostream>
#include <list>

using namespace std;
int hash1(int key) {
    return key % 100;
}

template<typename T>
void insert(list<T> array[], int x) {
    int hashValue = hash1(x);
    array[hashValue].push_front(x);
}
int main(void)
{
    list<int> array[100];
    insert(array, 50);
    insert(array, 23);
    insert(array, 423423);
    insert(array, 64363);
    insert(array, 7456);
    insert(array, 24089);
}