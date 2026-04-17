#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    vector<long long> factors;

    // Iterate up to the square root of N
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i); // i is a factor
            
            // If i is not the square root, add the paired factor n/i
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }

    // Sort factors in ascending order
    sort(factors.begin(), factors.end());

    // Print factors separated by spaces
    for (int i = 0; i < factors.size(); ++i) {
        cout << factors[i] << (i == factors.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
