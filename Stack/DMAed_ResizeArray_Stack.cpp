#include <iostream>
using namespace std;

// finding the size of the dynamically allocated array returns unsigned int,
// but top is signed int. 

// this implementation runs into so many problems - probably simpler in Java. 

const int STARTING_SIZE = 10;

class Stack {
    private:
    // DMA'd array to hold stack integer elements
    int* array;
    // top holds the index of the top element in the stack
    int top;
    unsigned int size;  // number of current elements in the array 
    public:
    Stack() { top = -1; size = 0; array = new int[STARTING_SIZE]; }
    ~Stack() { delete array; }
    bool isEmpty() { return top == -1; }
    void Pop() { 
        if (top != -1) { --top, --size; }
        else cout << "Stack is empty.\n";
    }
    void Push(int data) {
        unsigned int array_size = sizeof(array)/sizeof(int);    // number of elements allocated in the array
        if (size == array_size) {
            int* tempArray = new int[array_size * 2];
            for (size_t i = 0; i < array_size; ++i) {
                *(tempArray + i) = *(array + i);
            }
            delete array;
            array = tempArray;
        }
        ++top, ++size;
        *(array + top) = data;
        //cout << *(array + top) << endl;
    }
    int Top() {
        return *(array + top);
    }
    void PrintData() {
        for (size_t i = 0; i < size; ++i) {
            cout << *(array + i) << endl;
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

    return 0;
}