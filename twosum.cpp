#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {}; // Should not reach here based on problem constraints
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = sol.twoSum(nums1, target1);
    std::cout << "Example 1 Output: [" << result1[0] << "," << result1[1] << "]" << std::endl;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = sol.twoSum(nums2, target2);
    std::cout << "Example 2 Output: [" << result2[0] << "," << result2[1] << "]" << std::endl;

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = sol.twoSum(nums3, target3);
    std::cout << "Example 3 Output: [" << result3[0] << "," << result3[1] << "]" << std::endl;

    return 0;
}