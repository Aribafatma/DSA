#include <iostream>

using namespace std;

int main() {
    int N, M;
    
    // Read the two input integers
    if (cin >> N >> M) {
        // Print results in the required format
        cout << N << " + " << M << " = " << (N + M) << endl;
        cout << N << " - " << M << " = " << (N - M) << endl;
        cout << N << " * " << M << " = " << (N * M) << endl;
        cout << N << " / " << M << " = " << (N / M) << endl;
        cout << N << " % " << M << " = " << (N % M) << endl;
    }
    
    return 0;
}
