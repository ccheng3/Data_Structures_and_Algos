/* Chris Cheng
 * 06/30/2020
 */

/* This program practices a Recursive implementation of the Fibonacci sequence.
 * The function takes the sequence number to be found as argument, and returns
 * the integer at that seq. number in the Fibonacci sequence.
 */

#include <iostream>
using namespace std;

int Fib(int n) {
	if (n == 2 || n == 1) {
		return 1;
	}		
	return Fib(n - 1) + Fib(n - 2);
}

int main() {
	long long int seq_num;

	cout << "Enter the number's sequence position that you desire to know: ";
	cin >> seq_num;
	cout << "The " << seq_num << "th number of the Fib sequence is: ";
	cout << Fib(seq_num) << endl;

	return 0;
}