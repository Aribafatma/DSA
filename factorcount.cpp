#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;
int divisors[MAXN + 1];

void precompute() {
    // Sieve-like approach to count divisors for all numbers up to MAXN
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int Q;
    if (!(cin >> Q)) return 0;

    while (Q--) {
        int x;
        cin >> x;
        cout << divisors[x] << "\n";
    }

    return 0;
}
