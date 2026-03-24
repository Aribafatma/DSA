#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    string s;

    while (n--) {
        cin >> s;
        if (s[1] == '+')  // middle character check
            ans++;
        else
            ans--;
    }

    cout << ans << endl;
    return 0;
}