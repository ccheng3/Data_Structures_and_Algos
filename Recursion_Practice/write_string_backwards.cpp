/* Chris Cheng
 * 09/08/2020
 * write_string_backwards.cpp
 */

/* This program practices two ways to writing a string backwards.
 * 
 * First function practices tail recursion, which is where the recursive function has statements execute, and then
 * a recursive call to the function executes. The statements execute with each additional recursive call (each additional
 * function call is pushed onto the call stack)
 * 
 * Second function practices head recursion, which is where the recursive function call executes first, then statements
 * execute afterwards. The statements do not execute until the recursive function call returns (removed from the call stack). */

/* Note: Best way to visualize the concept is to imagine how the regular function statements execute in relation to
 * recursive function calls on the call stack. Do the function statements execute after the recursive function call pops 
 * off the call stack, or before the recursive function call pushes onto the call stack? */

#include <iostream>
#include <string>
using namespace std;

// print the string backwards using tail recursion 
// (print last char, then recursive call with successive last chars removed from each smaller string)
// base case is when string is empty
void Print_String_Backwards_One(string s) {
    if (s.size() > 0) {
        cout << s.at(s.size() - 1) << endl;
        Print_String_Backwards_One(s.substr(0, s.size() - 1));
    }
}

// print the string backwards using head recursion 
// (recursive call with successive first chars removed from each smaller string)
// base case is when string is empty
void Print_String_Backwards_Two(string s) {
    if (s.size() > 0) {
        Print_String_Backwards_One(s.substr(1, s.size() - 1));
        cout << s.at(0) << endl;
    }
}

int main() {
    string my_string = "palindrome";
    //Print_String_Backwards_One(my_string);
    Print_String_Backwards_Two(my_string);
    return 0;
}