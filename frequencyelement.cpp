#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int main() {
    int N, Q;
    // Read N and Q
    if (!(cin >> N >> Q)) return 0;

    vector<long long> A(N);
    // Read the array A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array for binary search
    sort(A.begin(), A.end());

    // Process each query
    for (int k = 0; k < Q; ++k) {
        long long x, y;
        cin >> x >> y;

        // If x > y, the interval is empty
        if (x > y) {
            cout << 0 << endl;
            continue;
        }

        // Find the first element >= x
        auto it1 = lower_bound(A.begin(), A.end(), x);
        int left_bound = static_cast<int>(it1 - A.begin());

        // Find the first element > y
        auto it2 = upper_bound(A.begin(), A.end(), y);
        int right_bound = static_cast<int>(it2 - A.begin());

        // The count is the difference between the two bounds
        long long count = right_bound - left_bound;
        cout << count << endl;
    }

    return 0;
}