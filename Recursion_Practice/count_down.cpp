/* Chris Cheng
 * 09/08/2020
 * count_down.cpp
 */

/* Given an integer n > 0, this program writes a recursive function countDown thats prints out the 
 * integers n, n-1,...,to 1.
 */

#include <iostream>
using namespace std;

void countDown(int n) {
    if (n > 0) {
        cout << n << endl;
        countDown(n-1);
    }
}

int main() {
    countDown(5);
    return 0;
}