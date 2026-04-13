#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

void solve() {
    int N, Q;
    if (!(std::cin >> N >> Q)) return;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    for (int k = 0; k < Q; ++k) {
        long long z;
        std::cin >> z;

        auto it = std::lower_bound(A.begin(), A.end(), z);
        long long count = std::distance(it, A.end());
        
        std::cout << count << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}