#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000001;
int spf[MAXN];

// Precompute the Smallest Prime Factor (SPF) for every number up to 10^6
void sieve() {
    for (int i = 2; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

void solve() {
    int x;
    if (!(cin >> x)) return;
    
    bool first = true;
    while (x > 1) {
        int p = spf[x];
        int count = 0;
        // Count the exponent of the current prime factor
        while (x % p == 0) {
            count++;
            x /= p;
        }
        
        // Formatting output: space between factors
        if (!first) cout << " ";
        cout << p << "^" << count;
        first = false;
    }
    cout << "\n";
}

int main() {
    // Fast I/O is crucial for 10^6 queries
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }

    return 0;
}
