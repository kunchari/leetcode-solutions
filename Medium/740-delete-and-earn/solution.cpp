/*So the point is that we can either choose one number and delete all neighbours. 
What is we create a new vector where would be stored values' points. 
Then it basically becomes a robber-like problem. Since we take i we cannot take i-1 or i+1

Time Complexity: O(2*n + k) = O(n + k)
Find max -> n, go through vector once -> n, and once again through iterations to find the best result -> k (k is max element)
Space Complexity: O(k)

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        //we need to find max number to get vector's size
        int max = nums[0];
        for(int i = 0; i < n; i++)
        {
            if(max < nums[i]) max = nums[i];
        }

        vector<int> sums(max + 1, 0);

        for(int num : nums)
        {
            sums[num] += num;
        }

        int num1 = 0;
        int num2 = sums[0];

        for(int i = 1; i < sums.size(); i++)
        {
            int result = std::max(num1 + sums[i], num2);
            num1 = num2;
            num2 = result;
        }

        return num2;
    }
};
