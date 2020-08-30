/* Chris Cheng
 * 08/30/2020 
 */

/* This is a quick implementation of the Deque (double-ended queue) using a 
 * doubly linked-list with head and tail pointer. Since I implemented DLL
 * with head and tail dummy Nodes, I will practice using just head and 
 * tail pointers this time, which isn't super tedious ---> just have to 
 * continuously update head and tail pointers to point to most recent
 * head and tail Nodes. 
 */

/* Deque allows for insertion and deletion of elements at both front and back
 * of the queue. 
 * 
 * Use of doubly list includes "prev" pointer, which allows for O(1) deletion at 
 * the back of the list (otherwise would have to traverse thru list and find prev_to_tail Node
 * to remove tail Node, which would require O(N) time.
 * 
 * Conclusion: This Deque is a Doubly list implementation with the constraint that you can only insert and remove 
 * Nodes at the head and tail of the list. This makes the insert and remove functions actually 
 * easier to implement b/c you do not have to take care of the edge case where you insert/remove between two Nodes. 
 */

#include <iostream>
using namespace std;

class DLLNode {
    private:
        int data;
        DLLNode* next;
        DLLNode* prev;
    public:
        DLLNode(int arg_data = 0, DLLNode* arg_next = nullptr, DLLNode* arg_prev = nullptr) :
        data(arg_data), next(arg_next), prev(arg_prev) {}
        int Get_Data() const { return data; }
        DLLNode* Get_Next() const { return next; }
        DLLNode* Get_Prev() const { return prev; }
        void Set_Data(int arg_data) { data = arg_data; }
        void Set_Next(DLLNode* nextNode) { next = nextNode; }
        void Set_Prev(DLLNode* prevNode) { prev = prevNode; } 
};

class Queue {
    private:
        DLLNode* front;
        DLLNode* back;
        int size;  
    public:
        Queue(DLLNode* arg_front = nullptr, DLLNode* arg_back = nullptr) : front(arg_front), back(arg_back) { size = 0; }
        ~Queue() { Clear(); }
        void Push_Back(int arg_data) {
            DLLNode* newNode = new DLLNode(arg_data);
            if (!Get_Size()) {
                front = back = newNode;
            }
            else {
                newNode->Set_Next(back->Get_Next());
                back->Set_Next(newNode);
                newNode->Set_Prev(back);
                back = newNode;
            }
            ++size;
        } 
        void Push_Front(int arg_data) {
            DLLNode* newNode = new DLLNode(arg_data);
            if (!Get_Size()) {
                front = back = newNode;
            }
            else {
                newNode->Set_Next(front);
                front->Set_Prev(newNode);
                front = newNode;
            }
            ++size;
        }
        void Pop_Back() {
            DLLNode* tempPtr;
            if (!Get_Size()) {
                cout << "Queue is empty.\n";
            }
            else {
                tempPtr = back;
                back = back->Get_Prev();
                back->Set_Next(nullptr);
                delete tempPtr;
                --size;
            }
        }
        void Pop_Front() {
            DLLNode* tempPtr;
            if (!Get_Size()) {
                cout << "Queue is empty.\n";
            }
            else {
                tempPtr = front;
                front = front->Get_Next();
                front->Set_Prev(nullptr);
                delete tempPtr;
                --size;
            }
        }
        int Front() const { 
            if (front) return front->Get_Data(); 
            else {
                cout << "Queue is empty.\n";
                return -1;
            } 
        }
        int Back() const {
            if (back) return back->Get_Data(); 
            else {
                cout << "Queue is empty.\n";
                return -1;
            }
        }
        int Get_Size() const { return size; }
        bool isEmpty() const { return size == 0; }
        void Clear() {
            // free all of the Nodes in the list
            // call this in the Dtor
            DLLNode* tempPtr = front;
            while (tempPtr) {
                front = front->Get_Next();
                delete tempPtr;
                tempPtr = front;
            }
            front = back = nullptr;
            size = 0;
        }
        void Print_Data() {
            DLLNode* tempPtr = front;
            while (tempPtr) {
                cout << tempPtr->Get_Data() << " ";
                tempPtr = tempPtr->Get_Next();
            }
            cout << endl << "Number of elements is: " << Get_Size() << endl;
            cout << "Front element is: " << Front() << endl;
            cout << "Back element is: " << Back() << endl;
        }
};

int main() {
    Queue my_queue; 

    for (int i = 0; i < 5; ++i) {
        my_queue.Push_Back(i+1);
    }
    for (int i = 0; i < 5; ++i) {
        my_queue.Push_Front((i+1)*12);
    }
    for (int i = 0; i < 4; ++i) {
        if (i > 1) my_queue.Pop_Front();
        else my_queue.Pop_Back();
    }
    my_queue.Print_Data();

    my_queue.Clear();
    my_queue.Print_Data();
    for (int i = 0; i < 5; ++i) {
        my_queue.Push_Back(i+10);
    }
    my_queue.Print_Data();

    return 0;
}