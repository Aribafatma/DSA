#include <iostream>
using namespace std;

const int MAXN = 105;

int parent[MAXN];
int lcp[MAXN][MAXN];
int dp[MAXN][MAXN];
char res[MAXN];

// DSU find
int find_set(int x) {
    if (parent[x] != x)
        parent[x] = find_set(parent[x]);
    return parent[x];
}

// DSU union
void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

int main() {
    int n;
    cin >> n;

    // input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> lcp[i][j];

    // init DSU
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Step 1: Union
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lcp[i][j] > 0)
                unite(i, j);
        }
    }

    // Step 2: Assign characters
    char groupChar[MAXN];
    for (int i = 0; i < n; i++) groupChar[i] = 0;

    char ch = 'a';

    for (int i = 0; i < n; i++) {
        int p = find_set(i);

        if (groupChar[p] == 0) {
            if (ch > 'z') {
                cout << "No valid string\n";
                return 0;
            }
            groupChar[p] = ch++;
        }

        res[i] = groupChar[p];
    }

    // Step 3: Recompute LCP
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (res[i] == res[j]) {
                if (i + 1 < n && j + 1 < n)
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = 1;
            }
        }
    }

    // Step 4: Validate
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != lcp[i][j]) {
                cout << "No valid string\n";
                return 0;
            }
        }
    }

    // output result
    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << endl;

    return 0;
}