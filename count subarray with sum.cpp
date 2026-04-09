#include <iostream>
#include <vector>
#include <map>

void solve() {
    long long n, x;
    if (!(std::cin >> n >> x)) return;

    std::map<long long, long long> counts;
    counts[0] = 1; // Initialize map with a count of 1 for a prefix sum of 0
    long long current_sum = 0;
    long long total_subarrays = 0;

    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        current_sum += a;

        // Check if a previous sum exists such that current_sum - previous_sum == x
        if (counts.count(current_sum - x)) {
            total_subarrays += counts[current_sum - x];
        }

        // Increment the count of the current prefix sum
        counts[current_sum]++;
    }

    std::cout << total_subarrays << std::endl;
}

int main() {
    solve();
    return 0;
}
