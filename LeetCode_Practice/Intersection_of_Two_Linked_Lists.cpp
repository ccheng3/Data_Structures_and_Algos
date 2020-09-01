/* Chris Cheng
 * 08/31/2020
 * Intersection of Two LinkedLists - Leetcode 160 (Easy) 
 */

/* I will practice both the stack-based solution (better than brute force but uses O(N) external memory)
 * and the optimal solution using the pointer-length-subtraction trick ---> O(N) runtime and O(1) space complexity
 * 
 * The brute force solution uses the O(N^2) idea of comparing every Node with every other Node in the problem.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ((!headA && !headB) || !headA || !headB) {
            return nullptr;
        }
        // push both lists' sequence of Node mem locs into two stacks
        stack<ListNode*> stack_one;
        stack<ListNode*> stack_two;
        ListNode* tempPtr_one = headA;
        ListNode* tempPtr_two = headB;
        while (tempPtr_one) {
            stack_one.push(tempPtr_one);
            tempPtr_one = tempPtr_one->next;
        }
        while (tempPtr_two) {
            stack_two.push(tempPtr_two);
            tempPtr_two = tempPtr_two->next;
        }
        // pop off Node mem locs and store a copy in a storage variable while mem locs are equal
        ListNode* intersection_node = nullptr;
        while (!stack_one.empty() && !stack_two.empty()) {
            if (stack_one.top() == stack_two.top()) {
                intersection_node = stack_one.top();
                stack_one.pop();
                stack_two.pop();
            }
            else if (stack_one.top() != stack_two.top() && intersection_node == nullptr) {
                return nullptr;
            } 
            else {
                return intersection_node;
            }
        }
        return intersection_node;
    }
};


/* Chris Cheng
 * 08/31/2020
 * 
 * Optimal Solution - move the longer list's tempPtr thru the list with distance equal
 * to the difference in lengths of the two lists, then compare for the intersecting Node
 * while neither of the two tempPtrs is pointing to NULL.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ((!headA && !headB) || !headA || !headB) {
            return nullptr;
        }
        // find the sizes of both lists, then find the difference and move the longer list's tempPtr
        // down it's list the number of times equal to the difference 
        int listA_size = 0;
        int listB_size = 0;
        ListNode* tempPtr_A = headA;
        ListNode* tempPtr_B = headB;
        ListNode* tempPtr = headA;
        while (tempPtr) {
            ++listA_size;
            tempPtr = tempPtr->next;
        }
        tempPtr = headB;
        while (tempPtr) {
            ++listB_size;
            tempPtr = tempPtr->next;
        }
        int diff;
        // if list A is longer then move list A's tempPtr equal to the difference
        if (listA_size > listB_size) {
            diff = listA_size - listB_size;
            for (int i = 0; i < diff; ++i) {
                tempPtr_A = tempPtr_A->next;
            }
        }
        // otherwise if list B is longer or equal length, do same reasoning
        if (listA_size <= listB_size) {
            diff = listB_size - listA_size;
            for (int i = 0; i < diff; ++i) {
                tempPtr_B = tempPtr_B->next;
            }
        }
        // check for the existence of the intersecting node while neither of the two tempPtrs
        // are pointing to nullptr.
        while (tempPtr_A && tempPtr_B) {
            if (tempPtr_A == tempPtr_B) {
                return tempPtr_A;
            }
            tempPtr_A = tempPtr_A->next;
            tempPtr_B = tempPtr_B->next;
        }
        return nullptr;
    }
};