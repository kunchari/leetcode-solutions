/*Almost the same problem as a n-th Fibonacci number, but requires 3 previous numbers. 
That's why I can use a little bit modified iterative solution I've done before.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int tribonacci(int n) {
        //basic cases: T(0)=0, T(1)=1, T(2)=1
        if (n == 0) return 0;
        if (n <= 2) return 1;

        int prev3 = 0; // T(i-3)
        int prev2 = 1; // T(i-2)
        int prev1 = 1; // T(i-1)
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};
