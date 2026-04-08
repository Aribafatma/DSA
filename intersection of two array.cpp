#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    set<int> A, result;

    // Input array A
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }

    cin >> m;

    // Input array B and find intersection
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (A.count(x)) {
            result.insert(x);
        }
    }

    // Output
    cout << result.size() << endl;

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
