// Time Complexity: O(n)
// Space Complexity: O(n)
#include <vector>

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        //Using vector to store already counted results
        //Filling n + 1 elements with -1
        std::vector<int> memo(n + 1, -1);
        return fibonacci(n, memo);
    }
private:
    //Pasing vector with (&) reference to prevent copying
    int fibonacci(int n, std::vector<int>& memo) {
        if (n <= 1) return n;

        //If already counted - return
        if (memo[n] != -1) return memo[n];

        //If not - count and save
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
        return memo[n];
    }
};
