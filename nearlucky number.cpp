#include <iostream>
#include <string>
#include <algorithm>

void solve() {
    std::string n_str;
    std::cin >> n_str;
    int lucky_count = 0;
    for (char c : n_str) {
        if (c == '4' || c == '7') {
            lucky_count++;
        }
    }

    if (lucky_count == 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::string count_str = std::to_string(lucky_count);
    bool is_nearly_lucky = true;
    for (char c : count_str) {
        if (c != '4' && c != '7') {
            is_nearly_lucky = false;
            break;
        }
    }

    if (is_nearly_lucky) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    solve();
    return 0;
}
