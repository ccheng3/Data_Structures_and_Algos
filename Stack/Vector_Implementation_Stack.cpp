/* Chris Cheng 
 * 08/21/2020
 * Stack Implementation Using a Vector (Dynamic Array) 
 */

#include <iostream>
#include <vector>
using namespace std;

class Stack {
    private:
    vector<int> my_vector;

    public:
    bool isEmpty() { return my_vector.size() == 0; }
    void Push(int data) { my_vector.push_back(data); }
    void Pop() { my_vector.pop_back(); }
    int Top() { return my_vector.back(); }
    void PrintData() { 
        for (int i = my_vector.size() - 1; i >= 0; --i) {
            cout << my_vector.at(i) << endl;
        }
        cout << endl << endl;
    }
};

int main() {
    Stack my_stack;

    for (int i = 0; i < 5; ++i) {
        my_stack.Push(i+1);
    }
    my_stack.PrintData();
    for (int i = 0; i < 2; ++i) {
        my_stack.Pop();
    }
    my_stack.PrintData();
    for (int i = 0; i < 3; ++i) {
        my_stack.Push((i+1)*5);
    }
    my_stack.PrintData();

    return 0;
}