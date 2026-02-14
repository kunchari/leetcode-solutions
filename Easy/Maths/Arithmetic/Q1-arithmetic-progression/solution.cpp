/*We know that d = a_min - a_max / n - 1. If it's not dividable -> cannot be a sequence. Let's find min and max elements by walking through each element -> O(n)
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return true;

        int max = arr[0];
        int min = arr[0];

        for (int i = 0; i < n; i++) {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }

        int d = (max - min) / (n - 1);
        if ((max - min) % (n - 1) != 0) return false;
        //it's constant
        if (max == min) return true;

        std::unordered_set<int> seq(arr.begin(), arr.end());

        //if there has been duplicates (we have already checked for d = 0))
        if (seq.size() != n) return false;

        for (int i = 0; i < n; i++) {
            if (seq.find(min + i * d) == seq.end()) {
                return false;
            }
        }

        return true;   
    }     
};
