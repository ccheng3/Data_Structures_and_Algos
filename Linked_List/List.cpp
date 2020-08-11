#include <iostream>
#include "List.h"

void List::Insert_At_Cursor(int data) {
    Node* newNode = new Node(data);

    // inserting into an empty list
    if (_tail == nullptr) {
        _head = newNode;
        _tail = newNode;
        _current = newNode;
    }
    // inserting into a nonempty list (two-pointer technique)
    else {
        Node* tempPtr = _head;
        Node* prev_to_tempPtr = nullptr;
        while (tempPtr != _current) {
            prev_to_tempPtr = tempPtr;
            tempPtr = tempPtr->Get_Next();
        }
        // insert a new head Node
        if (prev_to_tempPtr == nullptr) {
            if (_current != _tail) {
                newNode->Set_Next(tempPtr);
                _head = newNode;
            }
            else {
                tempPtr->Set_Next(newNode);
                _tail = newNode;  
            }
        }
        // insert a new body Node or tail Node
        else {
            if (tempPtr == _tail) {
                tempPtr->Set_Next(newNode);
                _tail = newNode;
            }
            else {
                newNode->Set_Next(tempPtr);
                prev_to_tempPtr->Set_Next(newNode);
            }
        }
    }
}
void List::Push_Back(int data) {
    Node* tempPtr = _current;
    _current = _tail;
    Insert_At_Cursor(data);
    // inserting into empty list prior has cursor pointing to nothing,
    // so no need to change cursor back to null.
    if (Get_Size() == 1) {}
    else {
        _current = tempPtr;
    }
}
void List::Push_Front(int data) {
    Node* tempPtr = _current;
    _current = _head;
    Insert_At_Cursor(data);
    _current = tempPtr;
}
int List::Remove_At_Cursor() {
    // cannot remove Nodes from an empty list 
    if (Get_Size() == 0) {
        return -1;
    }
    Node* tempPtr = _head;
    Node* prev_to_tempPtr = nullptr;
    while (tempPtr != _current) {
        prev_to_tempPtr = tempPtr;
        tempPtr = tempPtr->Get_Next();
    }
    // remove at the tail, and update tail
    if (tempPtr == _tail) {
        prev_to_tempPtr->Set_Next(nullptr);
        _tail = prev_to_tempPtr;
        delete tempPtr;
    }
    // remove at the head
    else if (tempPtr == _head) {
        _head = tempPtr->Get_Next();
        tempPtr->Set_Next(nullptr);
        delete tempPtr;
    }
    // remove in the body 
    else {
        prev_to_tempPtr = tempPtr->Get_Next();
        tempPtr->Set_Next(nullptr);
        delete tempPtr;
    }
    return 0;
}
void List::Pop_Back() {
    Node* tempPtr = _current;
    _current = _tail;
    Remove_At_Cursor();
    _current = tempPtr;
}
void List::Pop_Front() {
    Node* tempPtr = _current;
    _current = _head;
    Remove_At_Cursor();
    _current = tempPtr;
}
// advance_cursor()
    // take circular_advance_cursor into account
void List::Advance_Cursor() {
    if (_current != nullptr) {
        _current = _current->Get_Next();
    }
    else {
        _current = _head;
    }
}

void List::Reset_Cursor() {
    _current = _head;
}

int List::Get_Size() {
    Node* tempPtr = _head;
    int num_nodes = 0;
    while (tempPtr != nullptr) {
        ++num_nodes;
        tempPtr = tempPtr->Get_Next();
    }
    return num_nodes;
}
bool List::Is_Empty() {
    return Get_Size() == 0;
}
void List::Clear() {
    Node* tempPtr = _head;
    while (tempPtr != nullptr) {
        _head = tempPtr->Get_Next();
        tempPtr->Set_Next(nullptr);
        delete tempPtr;
        tempPtr = _head;
    }
}

void List::Print_Cursor_Data() {
    std::cout << "Cursor currently point to datapoint: " 
         << _current->Get_Data() << std::endl;
}

// overloaded << operator to print all data contents to output
std::ostream& operator<<(std::ostream& out, const List& obj) {
    out << "The linked list data elements as follows: \n";
    Node* curr = obj.Get_Head();
    while (curr != nullptr) {
        out << curr->Get_Data() << " ";
        if (curr == obj.Get_Current()) {
            out << "[Cursor here] ";
        }
        if (curr == obj.Get_Head()) {
            out << "[Head here] ";
        }
        if (curr == obj.Get_Tail()) {
            out << "[Tail here] ";
        }
        out << std::endl;
        curr = curr->Get_Next();
    }
    return out;
}
