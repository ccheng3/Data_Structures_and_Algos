#include <iostream>
#include <stack>
#include <string>
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
    unsigned int i = 0;
    string Postfix = "";
    stack<char> my_stack;
    while (i < s.length()) {
        char currChar = s.at(i);
        if (isOperand(currChar)) {
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
            if ((!my_stack.empty()) && Prec(currChar) <= Prec(my_stack.top())) {
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

string PostfixtoInfix(string s) {
    unsigned int i = 0;
    stack<string> my_stack;
    string Infix = "", operand1, operand2;
    while (i < s.length()) {
        char currChar = s.at(i);
        if (isOperand(currChar)) {
            my_stack.push(to_string(currChar));
            ++i;
        }
        else {
            operand2 = my_stack.top();
            my_stack.pop();
            operand1 = my_stack.top();
            my_stack.pop();
            string full_string = '(' + operand1 + currChar + operand2 + ')';
            my_stack.push('(' + operand1 + currChar + operand2 + ')');
            ++i;
        }
    }
    Infix = my_stack.top();
    return Infix;
    // return "Hello";
}

int main() {
    // postfix expression should be ABC*+D-
    string infix_string = "(A+B)-C*(D/E)+G";
    cout << "Infix expression is: ";
    cout << infix_string << endl;
    cout << "Postfix expression is: " << InfixtoPostfix(infix_string) << endl;

    cout << "Conversion back to Infix is: " << PostfixtoInfix(InfixtoPostfix(infix_string)) << endl;

    return 0;
}