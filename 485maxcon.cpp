#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;     // current consecutive 1s
    int maxCount = 0;  // maximum consecutive 1s

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 0; // reset when 0 appears
        }
    }

    cout << maxCount;

    return 0;
}