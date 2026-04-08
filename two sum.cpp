#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    long long X;
    cin >> n >> X;

    unordered_set<long long> s;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if (s.count(X - x)) {
            cout << "TRUE" << endl;
            return 0;
        }

        s.insert(x);
    }

    cout << "FALSE" << endl;

    return 0;
}
