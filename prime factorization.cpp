#include <iostream>

using namespace std;

/**
 * Problem: G. Prime Factorisation
 * Time complexity: O(sqrt(N))
 * Space complexity: O(1)
 */

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    // Edge case: 1 has no prime factors
    if (n == 1) return 0;

    bool first = true;

    // Check for prime factors starting from 2 up to sqrt(n)
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            
            // Print formatting
            if (!first) cout << " ";
            cout << i << "^" << count;
            first = false;
        }
    }

    // If n > 1 after the loop, the remaining n is a prime factor
    if (n > 1) {
        if (!first) cout << " ";
        cout << n << "^1";
    }

    cout << endl;

    return 0;
}
