#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000], pos[1000], neg[1000];
    int p = 0, q = 0;

    // Input
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] >= 0)
            pos[p++] = arr[i];
        else
            neg[q++] = arr[i];
    }

    // Rearrange (alternate)
    int i = 0, j = 0, k = 0;
    while(i < p && j < q) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }

    // Print result
    for(int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }

    return 0;
}