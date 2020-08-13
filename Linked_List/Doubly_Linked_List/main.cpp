/* Chris Cheng
 * 08/12/2020
 * Doubly Linked-List Implementation
 * main.cpp DLL test file
 */

/* Program Design Description
 * 
 * This main() function tests out the Doubly Linked
 * List. Insertion at the End/Front, Deletion at the 
 * End/Front, Insertion and Deletion in the body
 * of the list. Print out all data stored in the list.
 * [Maybe sort the list?] 
 * Linear Search thru the list for a int data and 
 * report back the index of the item? 
 */

#include <iostream>
using namespace std;

#include "List.cpp"

int main() {
    DLList* my_list = new DLList;
    
    for (int i = 0; i < 10; ++i) {
        my_list->Push_Back(i+1);
    }
    //my_list->Advance_Cursor();
    for (int i = 0; i < 5; ++i) {
        my_list->Advance_Cursor();
    }
    for (int i = 500; i < 505; ++i) {
        my_list->Push_Front(i);
    }
    for (int i = 10; i <= 30; i += 10) {
        my_list->Insert_At_Cursor(i);
    }

    // The seg fault is b/c you cannot advance a 
    // cursor that is set to NULL. 
    
    // When inserting the FIRST node, I need to detect
    // it and point the cursor (current) to the first
    // Node.
        // make the correction in Insert_At_Cursor()

    my_list->Print_List_Data();




    for (int i = 0; i < 2; ++i) {
        my_list->Pop_Front();
    }
    for (int i = 0; i < 2; ++i) {
        my_list->Pop_Back();
    }
    // should move cursor to 30.
    for (int i = 0; i < 15; ++i) {
        my_list->Move_Back_Cursor();
        //my_list->Advance_Cursor();
    }

    my_list->Print_List_Data();

    my_list->Clear();
    my_list->Print_List_Data();


    return 0;
}