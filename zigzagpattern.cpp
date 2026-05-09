#include <iostream>

using namespace std;

// Recursive function to print the zig-zag sequence
void printZigZag(int n) {
    // Base case: if n is 1, print it and stop the recursion
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    // Print current number (on the way down)
    cout << n << endl;

    // Recursive call for the next smaller number
    printZigZag(n - 1);

    // Print current number again (on the way back up)
    cout << n << endl;
}

int main() {
    int n;
    if (cin >> n) {
        printZigZag(n);
    }
    return 0;
}
