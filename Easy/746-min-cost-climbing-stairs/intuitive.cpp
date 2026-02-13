/*As I understand this task, we can use memoization right here. 
The logic is that you can reach the step either by jumping 1 or 2 steps. 
So if we're on i-th stair we can reach it either from i-1-th or i-2-th. 
At this way we need to decide which one costs lese. So we should choose min{cost_dp[i - 1], cost_dp[i - 2]}. 
To have this values stored I'll create a vector where in cost_dp[i] would be stored min cost to reach i-th step + it's own value.  

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto number = cost.size();
        std::vector<int> cost_dp(number);

        //basic cases
        cost_dp[0] = cost[0];
        cost_dp[1] = cost[1];

        for(int i = 2; i < number; i++)
        {
            cost_dp[i] = std::min(cost_dp[i - 1], cost_dp[i - 2]) + cost[i];
        }

        //need to return number value
        return std::min(cost_dp[number - 1], cost_dp[number - 2]);

    }
};
