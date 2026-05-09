#include <iostream>

using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    // Base case: 0! is 1
    if (n == 0) {
        return 1;
    }
    // Recursive step: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int N;
    if (cin >> N) {
        cout << factorial(N) << endl;
    }
    return 0;
}
