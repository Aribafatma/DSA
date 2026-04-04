#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

void solve() {
    int N;
    // Read the length N
    if (!(std::cin >> N)) return; 

    std::string S;
    // Read the string S
    if (!(std::cin >> S)) return; 

    // Map to store the last seen index of each character
    std::unordered_map<char, int> last_seen;
    int max_length = 0;
    // Left pointer of the sliding window
    int left = 0; 

    for (int right = 0; right < N; ++right) {
        char current_char = S[right];

        // If the character is already in the map and its last seen index is within the current window
        if (last_seen.count(current_char) && last_seen[current_char] >= left) {
            // Move the left pointer past the last occurrence
            left = last_seen[current_char] + 1;
        }

        // Update the last seen index of the current character
        last_seen[current_char] = right;

        // Calculate the current window length and update max_length
        max_length = std::max(max_length, right - left + 1);
    }

    // Print the result
    std::cout << max_length << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}
