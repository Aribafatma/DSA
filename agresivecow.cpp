#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to check if it's possible to place K cows with a minimum distance D
bool canPlaceCows(long long D, const vector<long long>& stalls, int K) {
    int count = 1; // Place the first cow in the first stall
    long long lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPos >= D) {
            count++;
            lastPos = stalls[i];
        }
    }
    return count >= K;
}

int main() {
    int N, K;
    // Read input N and K
    if (!(cin >> N >> K)) return 0;

    vector<long long> stalls(N);
    // Read stall positions
    for (int i = 0; i < N; ++i) {
        cin >> stalls[i];
    }

    // Sort the stall positions
    sort(stalls.begin(), stalls.end());

    long long low = 0, high = stalls.back() - stalls.front();
    long long ans = 0;

    // Binary search for the largest minimum distance
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canPlaceCows(mid, stalls, K)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Print the result
    cout << ans << endl;

    return 0;
}
