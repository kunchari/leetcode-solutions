//Q1. Can Make Arithmetic Progression From Sequence
/*With arithmetic progression we know, that for any elements d | a - b, where d is the common difference. 
The first thought is that we may find the biggest/smallest number and the second biggest/smallest number, 
find their difference and then find if there is 2-nd - d value.
From complexity side it'll be 
1. find element 1 and 2 -> 2*n
2. find the difference
3. find the next n-2 numbers in array -> (n-2)*n

But that's unefficient. It'll always take n^2 as we always need to find an element in the unsorted array. 
So let's sort it, The fastest way we can do it is O(n*log(n)). I'll use MergeSort, a Devide and Conquer algorithm. 
Then go through all the elements to check if they can create the progression as it can only ascend/descend (or well constant if d=0).

Time Complexity: O(n*log(n))
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) return true;
        std::vector<int> sorted = MergeSort(arr);
        int d = sorted[1] - sorted[0];
        for(int i = 1; i < sorted.size() - 1; i++)
        {
            if (sorted[i + 1] - sorted[i] != d) return false; 
        }

        return true;
    }
private:
    std::vector<int> Merge(vector<int>& right, vector<int>& left)
    {
        vector<int> result;
        int i = 0, j = 0;

        while (i < right.size() && j < left.size()) {
            if (right[i] <= left[j]) {
                result.push_back(right[i++]);
            } else {
                result.push_back(left[j++]);
            }
        }

        while(i < right.size()) result.push_back(right[i++]);
        while(j < left.size())  result.push_back(left[j++]);

        return result;
    }

    std::vector<int> MergeSort(vector<int>& arr) {
        int number = arr.size();
        if (number <= 1) return arr;

        int mid = number / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        left = MergeSort(left);

        vector<int> right(arr.begin() + mid, arr.end());
        right = MergeSort(right);

        return Merge(left, right);
    }
};
