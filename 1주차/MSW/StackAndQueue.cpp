#include <iostream>

using namespace std;

template <typename Data>
struct Node {
    Node* Next;
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

        if (!head)
            head = newNode;
        else
            tail->Next = newNode;
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
            newNode->Next = head;
        head = newNode;
    }

    Data front()
    {
        if (!head)
            return;
        return head->data;
    }

    Data back()
    {
        if (!tail)
            return;
        return tail->data;
    }

    void insert(int index, Data data)
    {
        Node<Data>* newNode = new Node<Data>;
        newNode->data = data;
        newNode->Next = nullptr;

        Node<Data>* current = head;
        Node<Data>* previous = nullptr;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            previous = current;
            current = current->Next;
        }

        if (!previous)
        {
            if (!head)
                tail = newNode;

            newNode->Next = head;
            head = newNode;
        }
        else
        {
            previous->Next = newNode;
            newNode->Next = current;
        }
    }

    void insert(int index, Data data[], int num)
    {
        Node<Data>* current = head;
        Node<Data>* previous = nullptr;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            previous = current;
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
                head = firstNode;
            }
        }
        else
        {
            previous->Next = firstNode;
            lastNode->Next = current;
        }
    }

    void Delete(int index)
    {
        Node<Data>* current = head;
        Node<Data>* previous = nullptr;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            previous = current;
            current = current->Next;
        }

        previous->Next = current->Next;
        delete current;
    }

    void Delete(int index, int count)
    {
        Node<Data>* current = head;
        Node<Data>* previous = nullptr;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                cout << "연결리스트의 범위를 벗어났습니다" << endl;
                return;
            }

            previous = current;
            current = current->Next;
        }

        for (int i = 0; i < count; i++)
        {
            if (!current)
                return;
            previous->Next = current->Next;
            delete current;
            current = previous->Next;
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

////////////////////////////////////////////////////////////////////////////////////

template <typename Data>
class Stack : public SinglyLinkedList<Data>
{
public:
    void push(Data data)
    {
        push_back(data);
    }
    Data top()
    {
        return back();
    }
    Data pop()
    {
        Data temp = back();
        Delete(size() - 1);
        return temp;
    }
};

template <typename Data>
class Queue : public SinglyLinkedList<Data>
{
public:
    void push(Data data)
    {
        push_back(data);
    }
    Data Front()
    {
        return front();
    }

    Data pop()
    {
        Data temp = front();
        Delete(0);
        return temp;
    }
};