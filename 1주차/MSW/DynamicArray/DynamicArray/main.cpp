#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T* array;
    int top = -1;
    int length = 1;
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top + 1 == length;
    }
public:
    DynamicArray() {
        array = new T[length];
    }
    ~DynamicArray()
    {
        delete[] array;
    }

    void push_back(T data) {
        if (isFull())
        {
            length *= 2;
            T* temp = new T[length];
            for (int i = 0; i <= top; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        top++;
        array[top] = data;
    }

    T pop_back() {
        if (isEmpty()) {
            cout << "더 이상 원소가 없습니다" << endl;
        }
        else
        {
            top--;
            return array[top + 1];
        }
    }

    void insert(int index, T data) {
        if (top < index || index < 0)
        {
            cout << "인덱스가 배열의 범위를 벗어났습니다" << endl;
            return;
        }

        if (isFull())
        {
            length *= 2;
            T* temp = new T[length];
            for (int i = 0; i <= top; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }

        for (int i = top; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = data;
        top++;
    }

    void Delete(int index) {
        if (top < index || index < 0)
        {
            cout << "인덱스가 배열의 범위를 벗어났습니다" << endl;
            return;
        }

        for (int i = index + 1; i <= top; i++)
        {
            array[i - 1] = array[i];
        }

        top--;
    }

    T at(int i) {
        return array[i];
    }

    int size() {
        return length;
    }

    void clear() {
        top = -1;
    }
};

int main() {
    DynamicArray<int> dynamicArray;

    dynamicArray.push_back(1);
    dynamicArray.push_back(2);
    dynamicArray.push_back(3);
    dynamicArray.push_back(4);

    cout << "Size: " << dynamicArray.size() << endl;

    dynamicArray.insert(2, 5);
    cout << "인덱스 2에 5를 삽입했습니다." << endl;

    cout << "마지막 원소를 제거했습니다. 마지막 원소: " << dynamicArray.pop_back() << endl;

    cout << "Size: " << dynamicArray.size() << endl;

    cout << "인덱스 2의 원소: " << dynamicArray.at(2) << endl;

    dynamicArray.clear();
    cout << "배열을 초기화했습니다." << endl;

    return 0;
}
