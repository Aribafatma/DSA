#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::string username;
    // Read the input string
    std::cin >> username;

    // Use a set to store unique characters
    std::set<char> distinct_chars;
    for (char c : username) {
        distinct_chars.insert(c);
    }

    // Get the count of distinct characters
    int count = distinct_chars.size();

    // Check the parity and print the output
    if (count % 2 == 0) {
        std::cout << "CHAT WITH HER!" << std::endl;
    } else {
        std::cout << "IGNORE HIM!" << std::endl;
    }

    return 0;
}