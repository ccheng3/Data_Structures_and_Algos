/* Chris Cheng
 * 09/07/2020
 * Palindrome LinkedList - 234
 */

/* The algo runs in O(N) time b/c you are traversing through the entire list, and it uses O(1) space b/c no external memory is
 * needed in this implementation. 
 * 
 * Three step process:
 * 1) find the middle of the list
 * 2) reverse the 2nd-half of the list using (starting from middle)
 * 3) compare Nodes for equality, converging from both sides of the list. 
 * 
 * You already traverse thru the entire list when finding the middle. 
 * Reversing the 2nd-half of the list is an additional traversal thru half of the list.
 * The comparison operation is yet an additional traversal thru the entire list.
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find middle of the list
        // empty list is palindrome
        if (head == nullptr) {
            return true;
        }
        // find middle of x >= 1 element list
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
            if (fast->next != nullptr) {
                fast = fast->next;
            }
        }
        // reverse 2nd-half of the list using three-pointer technique
        // prev anchors the reversed list 
        // curr facilitates the pointer reversal
        // forward anchors the un-reversed list 
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* forward = slow->next;
        ListNode* headTwo = nullptr;
        while (curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = forward;
            // update second head pointer and break out of loop if no more Nodes to reverse 
            if (curr == nullptr) {
                headTwo = prev;
                break;
            }
            forward = forward->next;
        }
        // compare Nodes while neither tempPtr equals to nullptr
        while (head != nullptr && headTwo != nullptr) {
            if (head->val != headTwo->val) {
                return false;
            }
            head = head->next;
            headTwo = headTwo->next;
        }
        return true;
    }
};