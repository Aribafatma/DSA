#include <iostream>

int main() {
    int x;
    // Read the input coordinate
    std::cin >> x;
    // Calculate the minimum number of steps using integer division
    int steps = (x + 4) / 5;
    // Print the result
    std::cout << steps << std::endl;
    return 0;
}