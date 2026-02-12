/*
This basically works like a Fibonacci numbers, you can reach the current stair either from the previous one or the one before it. 
So you sum the number of variants to get to the n - 1 and n - 2 stairs.
I'll use the iterative solution, as my favourite (a little modified).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1; // n = 1
        int prev1 = 2; // n = 2
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};
