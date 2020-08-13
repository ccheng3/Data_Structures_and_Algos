#ifndef NODE_H
#define NODE_H

class Node {
    private:
        int data;
        Node* _next;
    public:
        Node(int data_arg=0, Node* next=nullptr) : data(data_arg), _next(next) {}
        ~Node() {}
        int Get_Data() {
            return data;
        }
        void Set_Data(int nodeData) {
            data = nodeData;
        }
        Node* Get_Next() {
            return _next;
        }
        void Set_Next(Node* nextPtr) {
            _next = nextPtr;
        }
};

#endif