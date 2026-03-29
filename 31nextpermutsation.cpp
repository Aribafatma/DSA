#include <algorithm>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // Step 2: If a decreasing element is found, find the smallest element 
        // to its right that is larger than it, and swap them.
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the subarray from the decreasing element's index + 1 to the end.
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
