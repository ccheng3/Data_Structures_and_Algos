class Stack {
    private:
        class Node {
            private:
            Node* next;
            char data;
            public:
            Node(char arg_data, Node* arg_next = nullptr) : data(arg_data), next(arg_next) {}
            Node* GetNext() const { return next; }
            char GetData() const { return data; }
            void SetNext(Node* nextNode) { next = nextNode; }
        };
        Node* top;
    public:
        Stack(Node* arg_top = nullptr) : top(arg_top) {}
        bool isEmpty() { return !top; }
        void Push(char data) {
            Node* newNode = new Node(data);
            newNode->SetNext(top);
            top = newNode;
        }
        bool Pop() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return false;
            }
            Node* tempPtr = top;
            top = top->GetNext();
            delete tempPtr;
            return true;
        }
        char Top() {
            return top->GetData();
        }
};

class Solution {
public:
    bool isValid(string s) {
        Stack my_stack;
        for (int i = 0; i < s.length(); ++i) {
            char currchar = s.at(i);
            if ((currchar == ')' || currchar == '}' || currchar == ']') && (my_stack.isEmpty())) { 
                return false;
            }
            else if ((currchar == '(') || (currchar == '{') || (currchar == '[')) {
                my_stack.Push(s.at(i));
            }
            // difference btwn ASCII for '(' and ')' is 1, diff for {} and [] is 2. 
            // reduces amount of code you need to right as compared to original check
            // that currentchar is "{ or ( or [" and stack's top is "} or ) or ]" ,respectively.
            else if ((currchar - my_stack.Top() == 1) || (currchar - my_stack.Top() == 2))
                {
                    my_stack.Pop();
                    continue;
                }
            else {
                return false;
            }
        }
        if (my_stack.isEmpty()) return true;
        return false;
    }
};