/* Chris Cheng
 * 08/31/2020
 * Leetcode 125 - Valid Palindrome (Easy)
 */

/* */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string alphanum_string = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s.at(i))) {
                if (isupper(s.at(i))) {
                    alphanum_string.push_back(tolower(s.at(i)));
                }
                else { 
                    alphanum_string.push_back(s.at(i)); 
                }
            }
        }
        string alphanum_string_two = "";
        stack<char> my_stack;
        for (int i = 0; i < alphanum_string.size(); ++i) {
            my_stack.push(alphanum_string.at(i));
        }
        while (!my_stack.empty()) {
            alphanum_string_two.push_back(my_stack.top());
            my_stack.pop();
        }
        if (alphanum_string == alphanum_string_two) {
            return true;
        }
        return false;
    }
};