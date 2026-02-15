/*
Time Complexity: O(height*width)
Space Complexity: O(height*width)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int width   = grid[0].size();
        int height  = grid.size();
        vector<vector<int>> dp(height, vector<int>(width, 0));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < height; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for(int j = 1; j < width; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for(int i = 1; i < height; i++) {
            for(int j = 1; j < width; j++) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[height - 1][width - 1];
    }
};
