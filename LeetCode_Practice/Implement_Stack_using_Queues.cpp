/* Chris Cheng
 * 08/31/2020
 * Leetcode 225 - Implement Stack using Queues (Easy)
 */

/* Two ways of solving this problem:
 *
 * 1) Make the push() function expensive ---> O(N) runtime
 * 2) Make the pop() function expensive ---> also could worsen to O(N) runtime 
 */

/* EDIT: I don't think the "make push() expensive" method works here b/c it doesn't allow for 
 *       multiple pop() of the most recently-added element. */

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> queue_one;
    queue<int> queue_two;
public:
    
    /** Push element x onto stack. */
    void push(int x) {
        queue_one.push(x);
        /* queue_two.push(x);
            while (!queue_one.empty()) {
                queue_two.push(queue_one.front());
                queue_one.pop();
            }
            
            */
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // Make the pop() function expensive ---> O(N)
    int pop() {
        while(queue_one.size() != 1) {
            queue_two.push(queue_one.front());
            queue_one.pop();
        }        
        int top = queue_one.front();
        queue_one.pop();
        queue<int> tempQueue = queue_one;
        queue_one = queue_two;
        queue_two = tempQueue;
        return top;    
        /* return queue_one.front(); */
    }
    
    /** Get the top element. */
    int top() {
        return queue_one.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_one.empty() && queue_two.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */