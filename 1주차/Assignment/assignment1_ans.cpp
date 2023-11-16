// doubly linked list
#include <iostream>
using namespace std;
template<typename T>
struct Node {
    T data;
    Node<T> *prev, *next;
    Node(T val = NULL) {
        data = val;
        prev = next = nullptr;
    }
};

template<typename T>
class CircularDoublyLinkedList {
    Node<T> *head, *tail;
    int length;
public:
    CircularDoublyLinkedList() {
        // dummy노드를 삽입한다.
        head = new Node<T>();
        tail = new Node<T>();
        head->next = head->prev = tail;
        tail->prev = tail->next = head;
        length = 0;
    }
    T front() { if (length > 0) return head->next->data; }
    T back() { if (length > 0) return tail->prev->data; }
    Node<T>* begin() { return head->next; }
    Node<T>* end() { return tail->prev; }
    int size() { return this->length; }

    void debug() {
        // head -> head까지 순회해본다. (go right)
        const Node<T> *fr = this->head->next, *bk = this->tail->prev;
        int counter = 0;
        Node<T> *cur = this->head->next;

        cout << "\n<< 출력 시작 >>\n";
        while (cur != fr || counter < 2 * length + 2) {
            if (cur != head && cur != tail)
                cout << cur->data << ' ';
            cur = cur->next;
            counter++;
        }

        cout << "\n======\n";
        // tail -> tail까지 순회해본다. (go left)
        cur = this->tail->prev;
        counter = 0;
        while (cur != bk || counter < 2 * length + 2) {
            if (cur != head && cur != tail)
                cout << cur->data << ' ';
            cur = cur->prev;
            counter++;
        }
    }

    // head -- ~~ -- tail
    // ~~영역에 끼워넣는다고 생각
    void push_back(T data) {
        insert(data, tail);
    }

    void push_front(T data) {
        insert(data, head->next);
    }

    void insert(T data, Node<T> *target) {
        assert(target != head && target != nullptr);
        // target 앞에 node를 삽입
        Node<T> *newNode = new Node<T>(data);
        newNode->next = target;
        newNode->prev = target->prev;
        target->prev->next = newNode;
        target->prev = newNode;
        length++;
    }

    void erase(Node<T> *target) {
        assert(target != nullptr);
        // head ~~ tail  // ~~사이에 있는 노드가 삭제된다
        target->prev->next = target->next;
        target->next->prev = target->prev;

        target->prev = target->next = nullptr;
        delete target;
        length--;
    }

    Node<T>* findFirst(T data) {
        Node<T> *cur = head->next;
        Node<T> *target = nullptr;
        while (cur != tail) {
            if (cur->data == data) {
                target = cur;
                break;
            }
            cur = cur->next;
        }
        return target;
    }
};

template<typename T>
class Deque {
    CircularDoublyLinkedList<T> list;
public:
    void push_back(T data) {
        list.push_back(data);
    }
    void push_front(T data) {
        list.push_front(data);
    }
    void pop_back() {
        list.erase(list.end());
    }
    void pop_front() {
        list.erase(list.begin());
    }
};

template<typename T>
class Stack {
    CircularDoublyLinkedList<T> list;
public:
    void push(T data) {
        list.push_back(data);
    }
    void pop() {
        list.erase(list.end());
    }
    T top() {
        return list.back();
    }
    int size() {
        return list.size();
    }
};

template<typename T>
class Queue {
    CircularDoublyLinkedList<T> list;
public:
    void push(T data) {
        list.push_back(data);
    }
    void pop() {
        list.erase(list.begin());
    }
    T front() {
        return list.front();
    }
    int size() {
        return list.size();
    }
};

int main(void) {

    /* Circular Doubly Linked List 테스트 */
    CircularDoublyLinkedList<int> cdl;
    cdl.push_back(100);
    cdl.push_back(200);
    cdl.push_back(300);
    cdl.push_back(400);
    cdl.push_front(90);
    cdl.push_front(80);
    cdl.debug();

    cout << "\ndel: 80\n";
    cdl.erase(cdl.findFirst(80)); // 첫번째 원소 삭제해보기
    cdl.debug();
    cout << "\ndel: 400\n";
    cdl.erase(cdl.findFirst(400)); // 마지막 원소 삭제해보기
    cdl.debug();
    cout << "\ndel: 200\n";
    cdl.erase(cdl.findFirst(200)); // 중간 노드 삭제해보기
    cdl.debug();

    // deque는 cdl을 wrapping한 형태이므로, 따로 테스트를 하지 않는다.

    // --------------------------

    /* stack 테스트 */
    cout << "\n=====stack=====\n";

    Stack<int> stk;
    for (int i = 0; i < 10; i++) {
        stk.push(i);
    }

    while (stk.size() > 0) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    cout << "\n=====queue=====\n";

    // ---------------
    /* queue 테스트 */
    Queue<int> queue;
    for (int i = 0; i < 10; i++) {
        queue.push(i);
    }
    while (queue.size() > 0) {
        cout << queue.front() << ' ';
        queue.pop();
    }
    cout << "\n=========\n";

    return 0;
}
