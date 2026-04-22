#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int lastN = N % 10;
    int lastM = M % 10;

    cout << lastN + lastM << '\n';

    return 0;
}
