#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int prices[100000];

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    cout << maxProfit;

    return 0;
}