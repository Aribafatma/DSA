#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // 1. Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Optimization: Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Optimization: Pruning (Early exit)
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Optimization: Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Optimization: Pruning for the second loop
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } 
                    else if (current_sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};