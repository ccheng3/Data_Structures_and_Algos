#include <iostream>
using namespace std;

int Collatz(int n) {
	if (n == 1) {
		return 0;
	}
	else if (n % 2 == 0) {
		return Collatz(n / 2) + 1;
	}
	return Collatz(3 * n + 1) + 1;
}

int main() {
	int num;

	cout << "Enter the starting number for your Collatz sequence,\n";
	cout << "Positive integers only: ";
	cin >> num;

	cout << Collatz(num) << endl;

	return 0;
}