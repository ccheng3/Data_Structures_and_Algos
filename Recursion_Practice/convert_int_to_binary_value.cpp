/* Chris Cheng
 * 10/04/2020
 * convert_int_to_binary_value.cpp
 */

/* This program converts a non-negative integer value to its equivalent binary value using a recursive design.
 */

#include <iostream>
using namespace std;

void int_to_binary(int value) {
   // base case --> implcitly --> if value == 0, then return from the function.
   if (value != 0) {
      // recursive case --> value is not zero, so check if even or odd then halve value
      int_to_binary(value / 2);
      if (value % 2 == 0) {
      cout << "0";
      }
      else {
         cout << "1";
      }
   }
}

// iterative solution is very straightforward - the pseudocode helped me extend to the recursive design
/* string binary_value = "";
   while (value != 0) {
      if (value is even) {
         append a zero to the string
      }
      else {
         append a one to the string
      }
      halve the value by dividing by 2
   }
   print the binary result string in reverse order (from back to front)
   // a more obvious way is just store the values in a stack and pop all the elements of the stack when printing. 
   */

int main() {
   int_to_binary(120); // binary value of decimal value "120" is "1111000" ---> 8+16+32+64 --> 8*15.
   cout << endl;
   int_to_binary(1000);
   cout << endl;
   return 0;
}