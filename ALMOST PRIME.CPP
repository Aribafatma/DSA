#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // prime_factors[i] will store the number of distinct prime factors of i
    vector<int> prime_factors(n + 1, 0);

    // Modified Sieve of Eratosthenes
    for (int i = 2; i <= n; ++i) {
        // If prime_factors[i] is 0, then i is a prime number
        if (prime_factors[i] == 0) {
            // Increment the count for all multiples of this prime
            for (int j = i; j <= n; j += i) {
                prime_factors[j]++;
            }
        }
    }

    int almost_prime_count = 0;
    for (int i = 1; i <= n; ++i) {
        // According to the problem, almost prime numbers have exactly 2 distinct prime factors
        if (prime_factors[i] == 2) {
            almost_prime_count++;
        }
    }

    cout << almost_prime_count << endl;

    return 0;
}
