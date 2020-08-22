/* Chris Cheng
 * 08/21/2020
 * Linked-List Implementation of Stack 
 */

/* NOTE: Linked-List Implementation of Stack does not need a IsFull() method b/c linkedlist 
 * can grow to accomodate any size and no resize required. */

#include <iostream>
using namespace std;

class Stack {
    private:
    class Node {
        private:
        int data;
        Node* next;
        public:
        Node (int arg_data = 0, Node* arg_next = nullptr) : data(arg_data), next(arg_next) {}
        int GetData() const { return data; }
        Node* GetNext() const { return next; }
        void SetNext(Node* next) { this->next = next; }
    };
    Node* top;
    public:
    Stack() { top = nullptr; }
    bool isEmpty() { return !top; }
    void Push(int data) {
        Node* newNode = new Node(data);
        newNode->SetNext(top);
        top = newNode;
    }
    void Pop() {
        if (!top) { 
            cout << "Stack is empty\n" << endl;
            return; }
        Node* tempPtr = top;
        top = top->GetNext();
        delete tempPtr;
        return;
    }
    int Top() {
        if (!top) {
            cout << "Stack is empty\n" << endl; 
            return 0;
        }
        return top->GetData();
    }
    void PrintData() {
        Node* tempPtr = top;
        while (tempPtr != nullptr) {
            cout << tempPtr->GetData() << endl;
            tempPtr = tempPtr->GetNext();
        }
    }
};

int main() {
    Stack my_stack;

    for (int i = 0; i < 5; ++i) {
        my_stack.Push(i+1);
    }
    for (int i = 0; i < 2; ++i) {
        my_stack.Pop();
    }
    for (int i = 0; i < 3; ++i) {
        my_stack.Push((i+1) * 5);
    }
    my_stack.PrintData();
    cout << "The stack is empty: " << boolalpha << my_stack.isEmpty() << endl;
    return 0;
}