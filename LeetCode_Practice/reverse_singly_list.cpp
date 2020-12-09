/* Chris Cheng 
 * 12/08/2020
 * Reverse a singly linked list recursively.
 */ 

Node* reverseList(Node* head) {
    // empty list and single node list are already reversed
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else if (head->next != NULL) {
        // recurse down a node; 
        // eventually chain-return a pointer to new head node.
        Node* curr = reverseList(head->next);
        // flip "next" node to point to current node.
        head->next->next = head;
        // current node's next points to NULL.
        head->next = NULL;
        // chain return that pointer to new head node. 
        return curr;
    }
    // return a pointer to "new" head node when you've recursed 
    // all the way to last node. 
    else {
        return head;
    }
}

// 12/09/2020 update
// I realized I had redundancy in the program and I don't actually need 
// that "else" clause b/c the first "if" condition will execute when
// the recursive call gets to the last node in the list (last node
// in the list before reversal becomes head node of reversed list)

Node* reverseList(Node* head) {
    // empty list and single node list are already reversed

    // 12/09/2020 EDIT: --> AND, recursive call to original "last" 
    // node also will just evaluate to TRUE here and return a pointer
    // to last node. 
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        // recurse down a node; 
        // eventually chain-return a pointer to new head node.
        Node* curr = reverseList(head->next);
        // flip "next" node to point to current node.
        head->next->next = head;
        // current node's next points to NULL.
        head->next = NULL;
        // chain return that pointer to new head node. 
        return curr;
    }
}