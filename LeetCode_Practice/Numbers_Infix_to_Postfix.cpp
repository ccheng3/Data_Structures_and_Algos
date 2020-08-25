/* Chris Cheng
 * 08/25/2020
 * Single-Digit convert Infix to Postfix, then evaluate Postfix for int solution
 * NOTE: The test cases work on local machine but Leetcode gets a
 * "reference binding to misaligned address error" that I do not know how to resolve. */

/* But the good thing is that I now understand how the single-digit Infix-to-Postfix-to-Evaluation algo
 * works now using the stack. */

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

bool isOperand(char c) {
    if ((c == '+') || (c == '-') || (c == '/') || (c == '*') ||
        (c == '(') || (c == ')')){
        return false;
    }
    return true;
}

int Prec(char c) {
    if ((c == '*') || (c == '/')) return 3;
    else if ((c == '+') || (c == '-')) return 2;
    return 1;   // left parenthesis '(' has the lowest precedence
}

string InfixtoPostfix(string s) {
    stack<char> my_stack;
    unsigned int i = 0;
    string Postfix = "";
    while (i < s.length()) {
        char currChar = s.at(i);
        // if blank space then just move to next character
        if (isblank(currChar)) {
            ++i;
        }
        else if (isOperand(currChar)) {
            Postfix.push_back(currChar);
            ++i;
        }
        else if (currChar == '(') {
            my_stack.push(currChar);
            ++i;
        }
        else if (currChar == ')') {
            while (my_stack.top() != '(') {
                Postfix.push_back(my_stack.top());
                my_stack.pop();
            }
            my_stack.pop();
            ++i;
        }
        else {
            if (!my_stack.empty() && Prec(currChar) <= Prec(my_stack.top())) {
                Postfix.push_back(my_stack.top());
                my_stack.pop();
            }
            else {
                my_stack.push(currChar);
                ++i;
            }
        }
    }
    while (!my_stack.empty()) {
        Postfix.push_back(my_stack.top());
        my_stack.pop();
    }
    return Postfix;
}

int Process(int op1, int op2, char operation) {
    if (operation == '+') return op1 + op2;
    else if (operation == '-') return op1 - op2;
    else if (operation == '*') return op1 * op2;
    return op1 / op2;
}

int PostfixtoSolution(string s) {
    stack<int> my_stack;
    for (unsigned int i = 0; i < s.length(); ++i) {
        char currChar = s.at(i);
        if (isOperand(currChar)) {
            my_stack.push(currChar - 48);
        }
        else {
            int op2 = my_stack.top();
            my_stack.pop();
            int op1 = my_stack.top();
            my_stack.pop();
            my_stack.push(Process(op1,op2,currChar));
        }
    }
    return my_stack.top();
}

int main() {
    //string Infix = "(1+2)-3*4";
    //string Infix = "(1+(4+5+2)-3)+(6+8)";
    string Infix = " 2-1 + 2 ";
    cout << "Infix expression is: " << Infix << endl;
    cout << "Postfix expression is: " << InfixtoPostfix(Infix) << endl;
    cout << "Integer solution is: " << PostfixtoSolution(InfixtoPostfix(Infix)) << endl;

    return 0;
}