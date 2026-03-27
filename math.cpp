#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> nums;
 
    // Extract numbers from the input string
    for (char c : s) {
        if (isdigit(c)) {
            nums.push_back(c - '0');
        }
    }
 
    // Sort the numbers in non-decreasing order
    std::sort(nums.begin(), nums.end());
 
    // Print the sorted sum
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << "+";
        }
    }
    std::cout << std::endl;
 
    return 0;
}