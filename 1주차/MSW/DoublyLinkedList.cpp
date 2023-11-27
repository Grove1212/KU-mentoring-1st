#include <iostream>

using namespace std;

template <typename Data>
struct Node {
    Node<Data>* Next;
    Node<Data>* Prev;
    Data data;
};

template <typename Data>
class SinglyLinkedList {
private:
    Node<Data>* head;
    Node<Data>* tail;
public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(Data data)
    {
        Node<Data>* newNode = new Node<Data>;
        newNode->data = data;
        newNode->Next = nullptr;
        newNode->Prev = nullptr;

        if (!head)
            head = newNode;
        else
        {
            tail->Next = newNode;
            newNode->Prev = tail;
        }
        tail = newNode;
    }

    void push_front(Data data)
    {
        Node<Data>* newNode = new Node<Data>;
        newNode->data = data;
        newNode->Next = nullptr;

        if (!head)
            tail = newNode;
        else
        {
            newNode->Next = head;
            head->Prev = newNode;
        }
        head = newNode;
    }

    void insert(int index, Data data)
    {
        Node<Data>* newNode = new Node<Data>;
        newNode->data = data;
        newNode->Next = nullptr;
        newNode->Prev = nullptr;

        Node<Data>* current = head;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            current = current->Next;
        }

        if (!previous)
        {
            if (!head)
                tail = newNode;

            newNode->Next = head;
            head->Prev = newNode;
            head = newNode;
        }
        else
        {
            current->Prev->Next = newNode;
            newNode->Prev = current->Prev;
            newNode->Next = current;
            current->Prev = newNode;
        }
    }

    void insert(int index, Data data[], int num)
    {
        Node<Data>* current = head;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            current = current->Next;
        }

        Node<Data>* firstNode = new Node<Data>;
        Node<Data>* lastNode = new Node<Data>;
        firstNode->data = data[0];
        firstNode->Next = nullptr;
        lastNode = firstNode;

        for (int i = 1; i < num; i++)
        {
            Node<Data>* newNode = new Node<Data>;
            newNode->data = data[i];
            newNode->Next = nullptr;
            lastNode->Next = newNode;
            lastNode = newNode;
        }

        if (!previous)
        {
            if (!head)
            {
                head = firstNode;
                tail = lastNode;
            }
            else
            {
                lastNode->Next = head;
                head->Prev = lastNode;
                head = firstNode;
            }
        }
        else
        {
            current->Prev->Next = firstNode;
            firstNode->Prev = current->Prev;
            lastNode->Next = current;
            current->Prev = lastNode;
        }
    }

    void Delete(int index)
    {
        Node<Data>* current = head;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            current = current->Next;
        }

        current->Prev->Next = current->Next;
        current->Next->Prev = current->Prev;
        delete current;
    }

    void Delete(int index, int count)
    {
        Node<Data>* current = head;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            current = current->Next;
        }

        for (int i = 0; i < count; i++)
        {
            if (!current)
                return;
            current->Prev->Next = current->Next;
            current->Next->Prev = current->Prev;
            Node<Data>* temp = current;
            current = current->Next;
            delete temp;
        }
    }

    int size()
    {
        int length = 0;
        Node<Data>* current = head;
        while (!current)
        {
            length++;
            current = current->Next;
        }
        return length;
    }
};