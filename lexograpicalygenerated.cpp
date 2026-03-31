#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;
        string word(len, '\0');
        vector<bool> fixed(len, false);

        // 1. Fill 'T' requirements
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != '\0' && word[i + j] != str2[j]) {
                        return ""; // Conflict between 'T' overlaps
                    }
                    word[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }

        for (int i = 0; i < len; ++i) {
            if (word[i] == '\0') word[i] = 'a';
        }

        // Check 'F' constraints and backtrack if necessary
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                while (word.substr(i, m) == str2) {
                    // Find the rightmost character in this window [i, i+m-1] that is NOT fixed
                    int pos = -1;
                    for (int j = m - 1; j >= 0; --j) {
                        if (!fixed[i + j]) {
                            pos = i + j;
                            break;
                        }
                    }

                    if (pos == -1) return ""; // All chars fixed by 'T', cannot satisfy 'F'

                    // Increment character at pos to smallest possible that breaks 'str2' match
                    if (word[pos] < 'z') {
                        word[pos]++;
                        
                        if (word.substr(i, m) == str2) continue; // Try incrementing again if still matching
                    } else {
                        return ""; // Cannot increment further
                    }
                }
            }
        }

        return word;
    }
};
