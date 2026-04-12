#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int N, Q;
    // Read N and Q
    if (!(std::cin >> N >> Q)) return 0;

    std::vector<long long> A(N);
    // Read the sorted array A
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Process each query
    for (int k = 0; k < Q; ++k) {
        long long x;
        std::cin >> x;

        // Use lower_bound to find the first element not less than x
        auto it = std::lower_bound(A.begin(), A.end(), x);
        int index = static_cast<int>(it - A.begin());

        // Check if x is found within the array bounds and matches
        if (index < N && A[index] == x) {
            // Output 1-based index
            std::cout << index + 1 << "\n";
        } else {
            // Output -1 if not found
            std::cout << -1 << "\n";
        }
    }

    return 0;
}