#include <iostream>
#include <string>
#include <cctype> // Required for toupper()

int main() {
    std::string word;
    // Read the single word input from the user
    std::cin >> word;

    // Check if the word is non-empty (problem constraint guarantees this)
    if (!word.empty()) {
        // Capitalize the first letter using the toupper function
        // Note: toupper takes an int (char promoted to int) and returns an int (char)
        word[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(word[0])));
    }

    // Output the modified word
    std::cout << word << std::endl;

    return 0;
}