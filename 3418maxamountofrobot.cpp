#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // Use long long for DP to prevent overflow, initialized to a very small number
        // dp[i][j][k] -> max money at (i, j) with k neutralizations used
        long long INF = 1e17;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        // Base Case: Starting cell (0, 0)
        dp[0][0][0] = coins[0][0];          // No neutralization used
        dp[0][0][1] = max(0, coins[0][0]);  // Used one neutralization if negative
        dp[0][0][2] = max(0, coins[0][0]);  // Using two at once is same as using one here

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; ++k) {
                    long long from_prev = -INF;

                    // Coming from top or left
                    if (i > 0) from_prev = max(from_prev, dp[i-1][j][k]);
                    if (j > 0) from_prev = max(from_prev, dp[i][j-1][k]);

                    // 1. Don't use a neutralization at this cell
                    if (from_prev != -INF) {
                        dp[i][j][k] = max(dp[i][j][k], from_prev + coins[i][j]);
                    }

                    // 2. Use a neutralization at this cell (if k > 0)
                    if (k > 0) {
                        long long from_prev_k_minus_1 = -INF;
                        if (i > 0) from_prev_k_minus_1 = max(from_prev_k_minus_1, dp[i-1][j][k-1]);
                        if (j > 0) from_prev_k_minus_1 = max(from_prev_k_minus_1, dp[i][j-1][k-1]);
                        
                        if (from_prev_k_minus_1 != -INF) {
                            dp[i][j][k] = max(dp[i][j][k], from_prev_k_minus_1); // Neutralize means +0
                        }
                    }
                }
            }
        }

        // The answer is the maximum value reaching the bottom-right corner with 0, 1, or 2 skips
        return (int)*max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
    }
};