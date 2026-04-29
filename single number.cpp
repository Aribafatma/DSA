#include <iostream>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        // XOR every number; pairs will become 0
        result ^= num;
    }

    std::cout << result << std::endl;

    return 0;
}
