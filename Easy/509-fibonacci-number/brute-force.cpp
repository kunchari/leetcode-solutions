/**
 * Problem: Fibonacci Number (LeetCode #509)
 * Approach: Recursive (Brute Force)
 * * Time Complexity: O(2^n) - Exponential growth due to redundant calculations.
 * Space Complexity: O(n) - Maximum depth of the recursion stack.
 */

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        return fib(n - 1) + fib(n - 2);
    }
};
