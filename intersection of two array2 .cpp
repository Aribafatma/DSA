#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    map<int, int> freq;
    vector<int> result;

    // Input array A
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    cin >> m;

    // Input array B and build intersection with multiplicity
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }

    // Sort result
    sort(result.begin(), result.end());

    // Output
    cout << result.size() << endl;

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
