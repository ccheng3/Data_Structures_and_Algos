/* Chris Cheng
 * 08/12/2020
 * Doubly Linked-List Implementation
 */

/* Program Design Description
 * 
 * This is an implementation of a Doubly Linked-List, using two
 * sentinel dummy nodes "header" and "trailer" for simpler
 * implementation. 

(Header and Trailer dummy nodes are abstracted away from the user, so 
user doesn't know about them. But the dummy nodes make the implementation
simpler b/c you do not have to write edge case conditions. 
Don't have to continuously update a _head or _tail pointer if dummy nodes
are used b/c dummy nodes will always be pointing to the most recent head
and tail nodes.)

* For linked-lists, the Five edge cases to watch out for are operations:
*
1) In an empty list.
2) In a list with one element
3) At the head of the list
4) At the tail of the list 
5) In the middle of the list

Doubly Linked-List provides O(1) insertion/deletion at the head and the 
tail of the list. The newly-implemented previous pointer allows
for access to previous Node from tail Node.

Doubly Linked-List insertion/deletion at head is O(1), and searching thru
list is still O(N). 

Insertion/deletion in middle of list is still O(N) though b/c you still
have to iterate from head or tail node to the target node.

 */

#include <iostream>

class DLLNode {
    private:
        int data;
        DLLNode* next;
        DLLNode* prev;
    public:
        // Ctor with default data element of zero, and next and prev
        // ptrs both pointing to NULL
        DLLNode(int data_arg = 0, DLLNode* next_arg = nullptr, 
                DLLNode* prev_arg = nullptr) 
        : data(data_arg), next(next_arg), prev(prev_arg) {}  
        void Set_Data(int data) { this->data = data; }
        void Set_Next(DLLNode* nextNodePtr) { next = nextNodePtr; }
        void Set_Prev(DLLNode* prevNodePtr) { prev = prevNodePtr; }
        int Get_Data() const { return data; }
        DLLNode* Get_Next() const { return next; }
        DLLNode* Get_Prev() const { return prev; }
};

class DLList {
    private:
        int size;               // number of elements in List excluding dummy Nodes
        DLLNode* header;         // dummy header node
        DLLNode* trailer;        // dummy trailer node
        DLLNode* current;       // pointer to current Node object (this is cursor)
    public:
        // DLList Ctor initializes size to 0, instantiates header and trailer
        // dummy nodes with header->next pointing to trailer, trailer->prev
        // pointing to header, and both header->prev and trailer->next 
        // pointing to NULL
        DLList() {
            size = 0;
            header = new DLLNode(-1);
            trailer = new DLLNode(-2);
            header->Set_Next(trailer);
            trailer->Set_Prev(header);
            current = nullptr;
        }
        // Dtor de-allocates the heap-allocated memory created in Ctor
        // also sets the pointers to NULL for safety 
        ~DLList() {
            delete header;
            delete trailer;
            header = nullptr, trailer = nullptr, current = nullptr;
        }
        int Get_List_Size() const { return size; }
        void Set_List_Size(int size_arg = 0) { size = size_arg; }
        DLLNode* Get_Header_Dummy_Node() const { return header; }
        DLLNode* Get_Trailer_Dummy_Node() const { return trailer; }
        bool IsEmpty() { return Get_Header_Dummy_Node()->Get_Next() == Get_Trailer_Dummy_Node(); }
        void Print_List_Data() {
            cout << "The Doubly Linked-List contents as follows:\n";
            DLLNode* tempPtr = Get_Header_Dummy_Node()->Get_Next();
            while (tempPtr != Get_Trailer_Dummy_Node()) {
                cout << tempPtr->Get_Data() << " ";
                if (tempPtr == current) {
                    cout << "CURSOR points here ";
                }
                if (tempPtr == Get_Header_Dummy_Node()->Get_Next()) {
                    cout << "This is header node. ";
                }
                if (tempPtr == Get_Trailer_Dummy_Node()->Get_Prev()) {
                    cout << "This is tail node. ";
                }
                cout << endl;
                tempPtr = tempPtr->Get_Next();
            }
            cout << endl;
        } 
        // insert the new Node in front of the Node that cursor
        // is pointing at
        DLList* Insert_At_Cursor(int data) {
            DLLNode* newNodePtr = new DLLNode(data);
            newNodePtr->Set_Next(current);
            newNodePtr->Set_Prev(current->Get_Prev());
            newNodePtr->Get_Prev()->Set_Next(newNodePtr);
            newNodePtr->Get_Next()->Set_Prev(newNodePtr);
            ++size;
            if (size == 1) {
                current = newNodePtr;
            }
            // return pointer to current DLList object
            return this;
        }
        DLList* Push_Front(int data) {
            DLLNode* tempPtr = current;
            current = Get_Header_Dummy_Node()->Get_Next();
            Insert_At_Cursor(data);
            current = tempPtr;
            return this;
        } 
        DLList* Push_Back(int data) {
            if (current != nullptr) {
                DLLNode* tempPtr = current;
                current = Get_Trailer_Dummy_Node();
                Insert_At_Cursor(data);
                current = tempPtr;
            }
            // adding into an empty list means that
            // cursor was pointing to NULL beforehand, so no need
            // to point cursor back to "beforehand" status
            // cursor points to first node after insertion is complete 
            // (Insert() function conditional to check for size==1)
            else {
                current = Get_Trailer_Dummy_Node();
                Insert_At_Cursor(data);
            }
            return this;
        }
        // remove Node that cursor is pointing at, cursor adjusted to point
        // to Node after deleted Node
        DLList* Remove_At_Cursor() {
            // link OUT current Node
            current->Get_Prev()->Set_Next(current->Get_Next());
            current->Get_Next()->Set_Prev(current->Get_Prev());
            DLLNode* tempPtr;
            // if deleting tail node, then current should reset to new tail node
            if (current == trailer->Get_Prev()) {
                tempPtr = current->Get_Prev();
            }
            // otherwise save pointer to Node after 
            // removed Node to repoint current Node
            else {
                tempPtr = current->Get_Next();
            }
            // remove current Node
            delete current;
            // repoint cursor to Node after removed Node  
            current = tempPtr;
            // decrement List element size
            --size;
            return this;
        }
        DLList* Pop_Back() {
            DLLNode* tempPtr = current;
            current = trailer->Get_Prev();
            Remove_At_Cursor();
            current = tempPtr;
            return this;
        }
        DLList* Pop_Front() {
            DLLNode* tempPtr = current;
            current = header->Get_Next();
            Remove_At_Cursor();
            current = tempPtr;
            return this;
        }
        DLList* Advance_Cursor() {
            // if cursor is not on the tail node, then advance forward
            if (current != trailer->Get_Prev()) {
                current = current->Get_Next();
            }
            // otherwise point cursor to head node
            else {
                current = header->Get_Next();
            }
            return this;
        }
        DLList* Move_Back_Cursor() {
            if (current != header->Get_Next()) {
                current = current->Get_Prev();
            }
            else {
                current = trailer->Get_Prev();
            }
            return this;
        }

        DLList* Clear() {
            current = Get_Header_Dummy_Node()->Get_Next();
            while (current != Get_Trailer_Dummy_Node()) {
                Remove_At_Cursor();
            }
            size = 0;
            return this;
        }
};




