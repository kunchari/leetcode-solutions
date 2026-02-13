//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto number = cost.size();

        int stair0 = cost[0];
        int stair1 = cost[1];

        for(int i = 2; i < number; i++)
        {
            int current = min(stair0, stair1 ) + cost[i];
            stair0 = stair1;
            stair1 = current;
        }

        return std::min(stair0, stair1);
    }
};
