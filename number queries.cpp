#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;
bool is_prime[MAXN];
int pref[MAXN];

void sieve(int n) {
    fill(is_prime + 2, is_prime + n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    
    // Build prefix sum array
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (is_prime[i] ? 1 : 0);
    }
}

int main() {
    // Fast I/O for large number of queries
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    sieve(N);

    while (Q--) {
        int L, R;
        cin >> L >> R;
        // The number of primes in [L, R] is pref[R] - pref[L-1]
        cout << pref[R] - pref[L - 1] << "\n";
    }

    return 0;
}
