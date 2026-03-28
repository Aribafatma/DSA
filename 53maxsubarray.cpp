#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; i++) {
        if (currentSum + arr[i] > arr[i])
            currentSum = currentSum + arr[i];
        else
            currentSum = arr[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    cout << maxSum;

    return 0;
}