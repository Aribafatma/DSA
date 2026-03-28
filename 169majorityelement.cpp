#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100000];   // max size as per constraint

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    cout << candidate;

    return 0;
}