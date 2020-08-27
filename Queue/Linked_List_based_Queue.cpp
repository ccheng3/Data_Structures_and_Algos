/* Chris Cheng 
 * 08/26/2020
 * Singly Linked-List implementation of Queue
 */

/* An implementation of the Queue data structure using a singly linked list. A lot more intuitive to
 * put together as compared to the array-based implementation. It just makes sense. 
 */

#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* next;
    public:
        Node(int arg_data = 0, Node* arg_next = nullptr) : data(arg_data), next(arg_next) {}
        int Get_Data() const { return data; }
        Node* Get_Next() const { return next; }
        void Set_Next(Node* arg) { next = arg; }
};

class Queue {
    private:
        Node* front;
        Node* back;
        int size; 
    public:
        Queue(Node* arg_front = nullptr, Node* arg_back = nullptr) : front(arg_front), back(arg_back) { size = 0; }
        Node* Get_Front() const { return front; }
        Node* Get_Back() const { return back; }
        int Get_Size() const { return size; }
        bool isEmpty() {
            if (size == 0) return true;
            return false;
        }
        void Clear() { 
            Node* tempPtr = front;
            while (tempPtr != back) {
                front = front->Get_Next();
                delete tempPtr;
                tempPtr = front;
            }
            delete tempPtr;
            front = back = nullptr;
        }
        void Push(int data) {
            Node* tempPtr = new Node(data);
            if (front == nullptr) {
                front = back = tempPtr;
            }
            else {
                tempPtr->Set_Next(back->Get_Next());
                back->Set_Next(tempPtr);
                // need to update "back" ptr to point to the new element at the back of the queue.
                back = back->Get_Next();
            }
            ++size;
        }
        void Pop() {
            if (isEmpty()) {
                cout << "Queue is empty.\n";
                return;
            }
            else {
                Node* tempPtr = front;
                front = front->Get_Next();
                delete tempPtr;
                --size;
            }
        }
        void Print_Data() {
            Node* tempPtr = front;
            while (tempPtr) {
                cout << tempPtr->Get_Data() << " ";
                tempPtr = tempPtr->Get_Next();
            }
            cout << endl;
        }

};

int main() {
    Queue my_queue;

    for (int i = 0; i < 10; ++i) {
        my_queue.Push(i+1);
    }
    cout << "My queue is empty: " << boolalpha << my_queue.isEmpty() << endl;
    my_queue.Print_Data();
    cout << "Number of elements is: " << my_queue.Get_Size() << endl;
    for (int i = 0; i < 5; ++i) {
        my_queue.Push((i+1)*5);
    }
    for (int i = 0; i < 2; ++i) {
        my_queue.Pop();
    }
    my_queue.Print_Data();
    cout << "Number of elements is: " << my_queue.Get_Size() << endl;

    return 0;
}