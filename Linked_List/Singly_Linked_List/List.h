#include "Node.h"
#ifndef LIST_H
#define LIST_H

class List {
    private:
        Node* _head;
        Node* _tail;
        Node* _current;     // two pointer technique implementation (&'s implementation
                            // is calls cursor _prev_to_curr)
    public:
        // List Ctor
        List(Node* _headptr = nullptr, 
            Node* _tailptr = nullptr, Node* _currentptr = nullptr) : _head(_headptr), 
            _tail(_tailptr), _current(_currentptr) {}
        ~List() {}
        Node* Get_Head() const {
            return _head;
        }
        Node* Get_Tail() const {
            return _tail;
        }
        Node* Get_Current() const {
            return _current;
        }
        // insert_at_cursor()
        void Insert_At_Cursor(int data);
            // push_back()
        void Push_Back(int data);
            // push_front()
        void Push_Front(int data);
        // remove_at_cursor()
        int Remove_At_Cursor();
            // pop_back()
        void Pop_Back();
            // pop_front()
        void Pop_Front();
        // advance_cursor()
            // take circular_advance_cursor into account
        void Advance_Cursor();
        void Reset_Cursor();
        // get_size()
        int Get_Size();
        // is_Empty()
        bool Is_Empty();
        void Clear();
        void Print_Cursor_Data();
};

    std::ostream& operator<<(std::ostream& out, const List& obj);


#endif 