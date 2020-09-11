/* Chris Cheng
 * 09/08/2020
 * recursive_binary_search.cpp
 */

/* This program practices the iterative implementation of binary search first,
 * then I practice the recursive implementation of binary search.
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int ARRAY_SIZE = 400;

// Binary Search returns the index of the target value if present,
// otherwise returns -1 (can't have negative index value in array) to indicate target not found
int Iterative_Binary_Search(const int my_array[], int target) {
    int low = 0, high = ARRAY_SIZE - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target < my_array[mid]) {
            high = mid - 1;
        }
        else if (target > my_array[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int Recursive_Binary_Search(const int my_array[], int target, int l, int h) {
    int index;
    // base case: exhausted search space and no match found
    if (l > h) {
        index = -1;
    }
    else {
        int mid = (l + h) / 2;
        if (target < my_array[mid]) {
            index = Recursive_Binary_Search(my_array, target, l, mid - 1);
        }
        else if (target > my_array[mid]) {
            index = Recursive_Binary_Search(my_array, target, mid + 1, h);
        }
        // base case: found match 
        else {
            index = mid;
        }
    }
    return index;
}

int main() {
    int my_array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        my_array[i] = rand() % 1000;
    }
    sort(my_array, my_array+ARRAY_SIZE);
    // for (int i = 0; i < 15; ++i) {
    //     cout << my_array[i] << endl;
    // }
    //cout << "The index that target is at is: " << Iterative_Binary_Search(my_array, 323) << endl; 
    cout << "The index that target is at is: " << Recursive_Binary_Search(my_array, 9, 0, ARRAY_SIZE - 1) << endl; 

    return 0;
}