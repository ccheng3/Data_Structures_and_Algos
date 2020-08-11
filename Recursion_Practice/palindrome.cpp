#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 4;

bool palindrome(string str) {
	// base case one ---> the string is 1 character or less
	if (str.length() <= 1) return true;
	// base case two ---> the string's outer two chars are not equal
	else if (str.at(0) != str.at(str.length() - 1)) return false;
	// recursive case ---> return the call with the first and last chars cut off
	else return palindrome(str.substr(1, str.length() - 2));
}

int main() {
	string string_array[ARRAY_SIZE] = {"abba", "baba", "racecar", "catharsis"};

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		cout << "The string \"" << string_array[i] << "\" is a palindrome ---> "
			  << boolalpha << palindrome(string_array[i]) << endl;
	}
	// cout << "The string \"abba\" is a palindrome:  " << boolalpha  
	// 	  << palindrome("abba") << endl;
	return 0;
}


/* "abba" test case:
	main()
		palindrome("abba");
	palindrome("abba");
		str = "abba";
		str length is 4, a == a
		palindrome("b")

	EDIT --> found the error, it was with the substr() method in <string>
	header file. 
		substr() takes two arguments, from left to right, the index of the 
		string to start subset at, and the number of total chars that you want in
		the substring. You want to do (string length - 2) to chop off the 
		right-end character, (string length - 1) retains the right-end char.  

	This was more of a problem in terms of the implementation 
	details of cpp and not actually a problem in terms of the pseudocode.  
*/