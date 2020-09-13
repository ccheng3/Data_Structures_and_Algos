/* Chris Cheng
 * 09/12/2020
 * towers_of_hanoi.cpp
 */

/* This program practices the recursive implementation of the Towers of Hanoi problem.
 * 
 * The goal is to move all of the discs from the source peg (peg A) to the destination
 * peg (peg C) using the temporary peg (peg B) as a "temporary holding peg". The 
 * constraint on this problem is that no larger disc can be placed above a smaller
 * disc when moving the the discs over to the destination peg. Also, only one
 * disc can be moved at a time (you can't just grab all the discs at once and move
 * them over to the destination peg).
 * 
 * The recursive solution is short and elegant, and is a great example of how
 * the Recursion divide-and-conquer technique manifests itself as a tree structure.
 */

#include <iostream>
using namespace std;

void TOH(int size, char source, char dest, char temp) {
    // base case: if only one disc to move, then move that disc
    if (size == 1) {
        cout << "Move from " << source << " to " << dest << endl;
        return;
    }
    // recursive case: move the top (n-1) discs from source to temp 
    // using destination as placeholder, then move the largest disc
    // from source to destination, then move the top (n-1) discs
    // from temp to destination using source as placeholder.
    TOH(size - 1, source, temp, dest);
    cout << "Move from " << source << " to " << dest << endl;
    TOH(size - 1, temp, dest, source);

    // draw the recursive calls' tree pattern to review the trace.
    // number of moves required for each disc (n == disc size)
    // is (2^n)-1. --> results in floor of ((2^n)-1)/2 moves to 
    // move the top (n-1) discs from source to temp using dest and
    // also from temp to dest using source, and then one move of the
    // largest disc from source to dest.

    // so for 4 discs --> requires 7 + 1 + 7 = 15 moves. 
    // for 3 discs --> requires 2^3-1 = 7 moves, as 3 + 1 + 3 moves.
}

int main() {
    TOH(3,'A','C','B');
    return 0;
}
