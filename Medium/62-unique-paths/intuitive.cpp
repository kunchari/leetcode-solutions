/*Okay, so we need to basically count for each cell amount of ways to get there. So if we're on the [i][j]-th cell, we can reach it from either [i - 1][j] or [i][j - 1], so we just sum results. To save some time we will concider if i = 0 we have 1 way to get there (by going right) and if j = 0 we have 1 way to get there. 

Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        //if it's a column or a row we only have 1 way to get there
        if(n == 1 || m == 1) return 1; 
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
