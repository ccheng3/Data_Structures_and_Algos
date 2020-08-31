/* Chris Cheng
 * 08/31/2020
 * Palindrome Number - Leetcode 9 (Easy)
 */

/* This problem seemed rather difficult in the beginning, but actually turned out to be quite 
 * interesting. 
 * 
 * My reasoning was pretty straight-forward. Any integer that is negative is not a palindrome b/c of the unary minus
 * operator. Also, any integer that contains zero as its right-most digit will not be a palindrome either b/c the 
 * zero is not conserved when the integer is reversed to test for palindrome-ness. 
 * 
 * However, 0 itself is a palindrome and 0 mod 10 is equal to zero so I corrected the error and have now made sure
 * that only integers with right-most digit being 0 AND the integer itself is not equal to zero are concluded as 
 * not palindromes. 
 * 
 * Then, I begin the process to determine if the filtered ints are palindromes. The process is pretty 
 * straight-forward by using a couple of programming techniques:
 * 
 * If the difference between the integer and its reverse integer is equal to zero, then I know that the 
 * integer must be a palindrome. Therefore, I use a loop and the modulus operator to iteratively "peel-off"
 * one right-most digit at a time and then reverse it into a storage variable by first multiplying
 * the value in the storage variable by ten, and then adding the "peeled-off" digit into the storage variable.
 * 
 * I then return the boolean evaluation of the difference between the integer and its reverse being equal
 * to zero or not. */

class Solution {
public:
    bool isPalindrome(int x) {
        if ((x < 0) || (x % 10 == 0 && x)) {
            return false;
        }
        int x_copy = x;
        // reverse int was corrected to hold larger number b/c reversing a large int value (as test case) can result
        // in a super large int value that (int) datatype can no longer store anymore,
        // so use (long long int) datatype. 
        long long int reverse_int = 0;
        do {
            reverse_int  = (reverse_int * 10) + (x % 10);
            x /= 10;
        } while(x != 0);
        return x_copy - reverse_int == 0;
    }
};