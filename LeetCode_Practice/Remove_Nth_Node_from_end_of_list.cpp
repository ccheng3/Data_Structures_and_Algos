/* Chris Cheng
 * 09/16/2020
 * Remove_Nth_Node_from_end_of_list.cpp
 */

/* First implementation is the Brute-force "two-pass" solution. 
 * Second implementation is the clever "optimal" solution using two-pointer technique. 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // empty list case
        if (head == nullptr) {
            return nullptr;
        }
        // one Node case
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }
        int size = 0;
        ListNode* tempPtr = head;
        while (tempPtr != nullptr) {
            ++size;
            tempPtr = tempPtr->next;
        }
        // x>=2 Node case, delete the head
        // this is separate b/c (size - n - 1) calculation for deleting head Node would always result in 
        // -1, a condition that loop never evaluates to True for. 
        if (size == n) {
            ListNode* tempPtr = head;
            head = head->next;
            delete tempPtr;
            return head;
        }
        // x>=2 Node case, delete a Node other than the head
        // (size - n - 1) calculation works with every Node excluding head Node
        int count = 0;
        tempPtr = head;
        while (count != size - n - 1) {
            tempPtr = tempPtr->next;
            ++count;
        }
        ListNode* anchorPtr = tempPtr->next;
        tempPtr->next = anchorPtr->next;
        delete anchorPtr;
        return head;
    }
};