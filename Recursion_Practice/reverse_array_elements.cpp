/* Chris Cheng
 * 09/10/2020
 * reverse_array_elements.cpp
 */

/* This program practices both an iterative implementation of reversing an array's contents,
 * then a recursive implementation. 
 * 
 * NOTE: recursive reverse of array uses same concept as recursive determine palindrome; 
 *       you simplify the problem space by sequentially narrowing the space's starting
 *       and ending index. (moving the starting index forward one space and the ending 
 *       index back one space narrows the space) 
 * 
 * I really would only use recursion if the iterative solution is not easy to do and 
 * the recursive solution produces a clear, concise, natural solution.
 */

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

void Iterative_Reverse_Array(int array[]) {
    for (int i = 0; i < ARRAY_SIZE / 2; ++i) {
        int temp = array[i];
        array[i] = array[ARRAY_SIZE - 1 - i];
        array[ARRAY_SIZE - 1 - i] = temp;
    }
}

void Recursive_Reverse_Array(int array[], int left_index, int right_index) {
    // base case: when the indices are the same or left >= right, then no more swaps
    // needed. (odd-numbered elements ends with left==right condition,
    // and even-numbered elements ends with left>right condition)
    if (left_index >= right_index) {
        return;
    }
    // recursive case: swap mirroring-position elements and recurse again with
    // updated left and right indices.
    int temp = array[left_index];
    array[left_index] = array[right_index];
    array[right_index] = temp;
    Recursive_Reverse_Array(array, left_index+1, right_index-1);
}

void Print(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int my_array[] = {1,2,3,4,5,6,7,8,9,10};

    Print(my_array);
    Recursive_Reverse_Array(my_array,0,ARRAY_SIZE-1);
    Print(my_array);
    return 0;
}