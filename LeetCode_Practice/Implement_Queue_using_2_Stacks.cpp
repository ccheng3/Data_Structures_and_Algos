class MyQueue {
private:
    stack<int> stack_one;
    stack<int> stack_two;
public:

    /** Push element x to the back of queue. */
    void push(int x) {
        stack_one.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // pop() re-uses the logic from peek() that if stack_two is empty then pop and push everything 
        // from stack_one into two and remove the top. 

        // Basically, pop() method is just a peek() with an addition removal of the current top. 
        int x = peek();
        stack_two.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (stack_two.empty()) {
            while (!stack_one.empty()) {
            stack_two.push(stack_one.top());
            stack_one.pop();
            }
        }
        return stack_two.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_one.empty() && stack_two.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */