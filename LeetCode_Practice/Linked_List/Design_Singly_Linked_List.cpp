/* Chris Cheng
 * 09/16/2020 
 */

/* For the "Design Linked List" Problem, I implemented a singly-list with head and tail pointers.
 * 
 * I traced the code to find the problem --> missed a step in inserting new tail Node. */

struct Node {
    int val;
    Node* next;
    Node(int arg_val) : val(arg_val), next(nullptr) {}
};

class MyLinkedList {
private:
    int size;
    Node* head;
    Node* tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // empty list case
        if (head == nullptr) {
            return -1;
        }
        // invalid index case
        if (!(index >= 0 && index < size)) {
            return -1;
        }
        Node* tempPtr = head;
        for (int i = 0; i < index; ++i) {
            tempPtr = tempPtr->next;
        }
        return tempPtr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            ++size;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
    // invalid index case
        if (!(index >= 0 && index <= size)) {
            return;
        }
    // add at head
        if (index == 0) {
            addAtHead(val);
            if (size == 1) {
                tail = head;
            }
        }
    // add at tail
        else if (index == size) {
            addAtTail(val);
            if (size == 1) {
                head = tail;
            }
        }
    // add in the body
        else {
            Node* tempPtr = head;
            for (int i = 0; i < index - 1; ++i) {
                tempPtr = tempPtr->next;
            }
            Node* newNode = new Node(val);
            newNode->next = tempPtr->next;
            tempPtr->next = newNode;
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // empty list case
        if (head == nullptr) {
            return;
        }
        // invalid index case
        if (!(index >= 0 && index <= size-1)) {
            return;
        }
        // delete at head
        if (index == 0) {
            Node* tempPtr = head;
            head = head->next;
            delete tempPtr;
            --size;
            if (size == 0) {
                head = tail = nullptr;
            }
        }
        // delete at tail
        else if (index == size - 1) {
            Node* tempPtr = head;
            for (int i = 0; i < index - 1; ++i) {
                tempPtr = tempPtr->next;
            }
            Node* anchorPtr = tempPtr->next;
            tail = tempPtr;
            delete anchorPtr;
            --size;
        }
        // delete in body
        else {
            Node* tempPtr = head;
            for (int i = 0; i < index - 1; ++i) {
                tempPtr = tempPtr->next;
            }
            Node* anchorPtr = tempPtr->next;
            tempPtr->next = anchorPtr->next;
            delete anchorPtr;
            --size;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */