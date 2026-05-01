#include <iostream>
using namespace std;

int rodCut(int price[], int n) {
    int dp[100];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int mx = -1;

        for (int j = 1; j <= i; j++) {
            mx = max(mx, price[j] + dp[i - j]);
        }

        dp[i] = mx;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int price[100];

    // input prices (1 to n)
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    cout << rodCut(price, n);

    return 0;
}
