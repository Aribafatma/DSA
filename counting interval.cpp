#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: C. Counting Intervals
 * We use long long to handle values up to 10^18.
 * Fast I/O is used for 10^5 queries.
 */

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    while (Q--) {
        int T;
        long long L, R;
        cin >> T >> L >> R;

        // Base condition: If L > R, output 0 as per instructions
        if (L > R) {
            cout << 0 << "\n";
            continue;
        }

        long long result = 0;
        if (T == 1) {
            // (L, R) -> Count is R - L - 1. 
            // Use max(0LL, ...) to handle cases like L=R where result would be -1.
            result = max(0LL, R - L - 1);
        } else if (T == 2) {
            // [L, R) -> Count is R - L
            result = R - L;
        } else if (T == 3) {
            // (L, R] -> Count is R - L
            result = R - L;
        } else if (T == 4) {
            // [L, R] -> Count is R - L + 1
            result = R - L + 1;
        }

        cout << result << "\n";
    }

    return 0;
}
