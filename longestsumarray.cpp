#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int maxLength = 0;
    long long currentSum = 0;
    int left = 0;

    for (int right = 0; right < N; ++right) {
        currentSum += A[right];
        while (currentSum >= K) {
            currentSum -= A[left];
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;
}

int main() {
    solve();
    return 0;
}