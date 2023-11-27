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
            cout << "�� �̻� ���Ұ� �����ϴ�" << endl;
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
            cout << "�ε����� �迭�� ������ ������ϴ�" << endl;
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
            cout << "�ε����� �迭�� ������ ������ϴ�" << endl;
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
    cout << "�ε��� 2�� 5�� �����߽��ϴ�." << endl;

    cout << "������ ���Ҹ� �����߽��ϴ�. ������ ����: " << dynamicArray.pop_back() << endl;

    cout << "Size: " << dynamicArray.size() << endl;

    cout << "�ε��� 2�� ����: " << dynamicArray.at(2) << endl;

    dynamicArray.clear();
    cout << "�迭�� �ʱ�ȭ�߽��ϴ�." << endl;

    return 0;
}
