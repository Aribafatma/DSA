#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Speed up I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Read the first element to initialize the minimum value
    long long current_val;
    cin >> current_val;
    long long min_val = current_val;

    // Iterate through the remaining n-1 elements
    for (int i = 1; i < n; ++i) {
        cin >> current_val;
        if (current_val < min_val) {
            min_val = current_val;
        }
    }

    cout << min_val << endl;

    return 0;
}
