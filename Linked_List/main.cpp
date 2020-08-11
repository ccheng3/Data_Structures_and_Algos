#include <iostream>
using namespace std;

#include "List.h"

int main() {
    List* my_list = new List();

    for (int i = 0; i < 2; ++i) {
        my_list->Push_Back(i+1);
    }
    for (int i = 0; i < 5; ++i) {
        my_list->Push_Front(i);
    }
    for (int i = 0; i < 5; ++i) {
        my_list->Pop_Back();
    }
    my_list->Reset_Cursor();
    // my_list->Print_Cursor_Data();
    // my_list->Reset_Cursor();
    // my_list->Print_Cursor_Data();
    
    // //my_list->Pop_Back();
    // for (int i = 0; i < 2; ++i) {
    //     my_list->Pop_Front();
    // }
    // my_list->Push_Back(1);
    // my_list->Push_Back(3);
    // my_list->Push_Back(4);
    // my_list->Advance_Cursor();
    my_list->Insert_At_Cursor(20);
    my_list->Insert_At_Cursor(30);
    my_list->Insert_At_Cursor(40);
    my_list->Insert_At_Cursor(50);

    for (int i = 0; i < 3; ++i) {
        my_list->Advance_Cursor();
    }
    for (int i = 0; i < 4; ++i) {
        my_list->Pop_Front();
    }
    // my_list->Pop_Back();
    // for (int i = 0; i < 10; ++i) {
    //     my_list->Insert_At_Cursor(20+i);
    // }

    cout << *my_list << endl;
    cout << my_list->Get_Size() << " elements in the linked list\n";
    cout << "The linked list is empty: " << boolalpha 
         << my_list->Is_Empty() << endl;


    my_list->Clear();
    cout << endl << endl << *my_list << endl;
    cout << my_list->Get_Size() << " elements in the linked list\n";    
    cout << "The linked list is empty: " << boolalpha 
         << my_list->Is_Empty() << endl;

    delete my_list;
    return 0;
}