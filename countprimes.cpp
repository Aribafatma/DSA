#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    // Initialize a boolean vector where true means the index is prime
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    // Sieve of Eratosthenes
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            // Update all multiples of p starting from p*p
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    // Count the number of primes remaining
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
