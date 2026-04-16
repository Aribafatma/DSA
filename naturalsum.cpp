#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (cin >> N) {
        // Use the formula N * (N + 1) / 2
        // Result is stored in long long to handle values up to ~4*10^18
        long long sum = N * (N + 1) / 2;
        cout << sum << endl;
    }

    return 0;
}
