/* Chris Cheng
 * 10/25/2020
 * MergeSort.cpp
 */

/* This is an implementation of MergeSort. MergeSort has runtime complexity of O(NlogN) and uses O(N) extra space.
 * MergeSort is an out-of-place sort b/c of the use of that auxiliary array to hold the sorted elements before copying
 * back to the original array. */

#include <iostream>
using namespace std;
const int NUM_ELEMENTS = 8;

void Merge(int array[], int low, int mid, int high) {
    int leftPos = low;                          // start of left sub-array
    int rightPos = mid + 1;                    // start of right sub-array
    int mergePos = 0;                           // current open position in aux_array that will store next sorted element
    int* aux_array = new int[high - low + 1];   // dynamically allocated aux_array that holds the sorted elements

    while ((leftPos <= mid) && (rightPos <= high)) {
        if (array[leftPos] < array[rightPos]) {
            aux_array[mergePos] = array[leftPos];
            ++leftPos;
        }
        else {
            aux_array[mergePos] = array[rightPos];
            ++rightPos;
        }
        ++mergePos;     // no matter what, mergePos has to advance after each comparison, so just put it after the comparison
    }
    
    while (leftPos <= mid) {
        aux_array[mergePos] = array[leftPos];   // only one of the two "clean-up" loops will execute
        ++mergePos, ++leftPos;
    }
    while (rightPos <= high) {
        aux_array[mergePos] = array[rightPos];
        ++mergePos, ++rightPos;
    }
    
    for (mergePos = 0; mergePos < high-low+1; ++mergePos) {
        array[low + mergePos] = aux_array[mergePos];            // NOTE: need to remember to add the offset amount "low" 
    }                                                           // The key --> remember that right sub-array starts at mid+1, and when
}                                                               // sorting the right subarray --> low is assigned mid+1. 

void MergeSort(int array[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid+1, high);
        Merge(array, low, mid, high);
    }
}

// print out the elements in the array 
void Print_Elements(int array[]) {
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int test_array[NUM_ELEMENTS];

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        test_array[i] = 100 - 2*i;
    }
    Print_Elements(test_array);
    MergeSort(test_array, 0, NUM_ELEMENTS-1);
    Print_Elements(test_array);
}

/* 
Conclusion:
    - MergeSort is pretty straightforward to understand after understanding how Recursion works.
    - The final step to understand is to trace thru an example and manually draw out the tree structure. 
*/