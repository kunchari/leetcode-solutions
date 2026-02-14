/*Imagine we can rob either 1st or 2nd house. We choose the best result between this two. 
That's quite easy. Now we have the third house and we have to choose either to rob the first one and the thrid one or only the second one. 
This leads us to the variant of the solution. We need to decide if we want to rob i-th house, so we look if i-2-th result + i-th cost is more or less than if we chose just to keep the result of i-1th house

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int number = nums.size();
        if (number == 0) return 0;
        if (number == 1) return nums[0];

        //we can only rob 1 house
        int house1 = nums[0];
        //we can only rob either 1st or 2nd house
        int house2 = std::max(nums[0], nums[1]);
        
        for(int i = 2; i < number; i++)
        {
            int current = std::max(house1 + nums[i], house2);
            house1 = house2;
            house2 = current;
        }

        //return the best result for the last house
        return house2;
    }
};
