#include <iostream>

int main() {
    long long n;
    int k;
    // Read input values for n and k
    std::cin >> n >> k;

    // Perform the wrong subtraction k times
    for (int i = 0; i < k; ++i) {
        if (n % 10 != 0) {
            n = n - 1;
        } else {
            n = n / 10;
        }
    }

    // Print the result after k subtractions
    std::cout << n << std::endl;

    return 0;
}