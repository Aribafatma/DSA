#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0) return false;  

        int original = n;
        long long revNum = 0;

        while (n != 0) {
            int digit = n % 10;
            revNum = revNum * 10 + digit;
            n /= 10;
        }

        return revNum == original;
    }
};

int main() {
    int x;
    cin >> x; 

    Solution sol;
    cout << (sol.isPalindrome(x) ? "true" : "false") << endl;

    return 0;
}