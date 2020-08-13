#include <iostream>

class DLLNode {
    private:
        int data;
        DLLNode* next;
        DLLNode* prev
    public:
        // Ctor with default data element of zero, and next and prev
        // ptrs both pointing to NULL
        DLLNode(int data_arg = 0, next_arg = nullptr, prev_arg = nullptr) 
        : data(data_arg), next(next_arg), prev(prev_arg) {}  
        void Set_Data(int data) { this.data = data; }
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
        }
        // Dtor de-allocates the heap-allocated memory created in Ctor
        ~DLList() {
            delete header;
            delete trailer;
        }
        int Get_List_Size() const { return size; }
        void Set_List_Size(int size_arg = 0) { size = size_arg; }
        DLLNode Get_Header_Dummy_Node() const { return header; }
        DLLNode Get_Trailer_Dummy_Node() const { return trailer; }
        bool IsEmpty() { return Get_Header_Dummy_Node().Get_Next() == Get_Trailer_Dummy_Node(); }
        void Print_List_Data() {
            DLLNode* tempPtr = Get_Header_Dummy_Node().Get_Next();
            while (tempPtr != Get_Trailer_Dummy_Node()) {
                cout << tempPtr->Get_Data() << " ";
                if (tempPtr == current) {
                    cout << "Cursor points here ";
                }
                if (tempPtr == Get_Header_Dummy_Node().Get_Next()) {
                    cout << "This is header node. ";
                }
                if (tempPtr == Get_Trailer_Dummy_Node().Get_Prev()) {
                    cout << "This is tail node. ";
                }
                tempPtr = tempPtr->Get_Next();
            }
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
            DLLNode* tempPtr = current;
            current = Get_Trailer_Dummy_Node();
            Insert_At_Cursor(data);
            current = tempPtr;
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
};

