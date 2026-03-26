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

    int result = 0;

    // XOR all elements
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }

    // Output single number
    cout << result;

    return 0;
}