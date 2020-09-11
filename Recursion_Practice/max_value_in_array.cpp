/* Chris Cheng
 * 09/08/2020
 * max_value_in_array.cpp
 */

/* This program finds the largest value in an array through a recursive approach.
 * 
 * The largest value in an array is the larger value between (the largest value from the left half of the array)
 * and (the largest value from the right half of the array).
 * 
 * Then you can notice that this definition contains a recursive decomposition behavior where the 
 * largest value from the left half of the array is itself a largest value of an array (with said array being
 * the left half of the whole array).
 * 
 * The behavior continues to decompose into smaller pieces of the same problem until the base case is reached.
 * Base case is where the array contains only one integer, and so that integer is therefore the max value of 
 * the array. 
 */

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 8;

int Larger(int a, int b) {
    return (a > b) ? a : b;
}

int MaxValue(const int array[], int start, int end) {
    if (start == end) { return array[start]; }
    else {
        int middle = (end - start) / 2 + start;
        int left_max = MaxValue(array,0,middle);
        int right_max = MaxValue(array,middle+1,end);
        return (left_max > right_max) ? left_max : right_max;  
        //return Larger(MaxValue(array,0,middle), MaxValue(array,middle+1,ARRAY_SIZE-1));
    }
}

int main() {
    int my_array[] = {1,2,3,4,5,6,7,5000};

    cout << "Largest value in the array is: " << MaxValue(my_array,0,ARRAY_SIZE-1) << endl;
    return 0;
}