#include <iostream>

using namespace std;

void solve() {
    long long n;
    if (!(cin >> n)) return;

    int distinct_prime_factors = 0;

    // Check for each factor from 2 up to sqrt(n)
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            // Found a distinct prime factor
            distinct_prime_factors++;
            
            // Remove all occurrences of this factor from n
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // If n > 1, the remaining n is a prime factor itself
    if (n > 1) {
        distinct_prime_factors++;
    }

    cout << distinct_prime_factors << endl;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
