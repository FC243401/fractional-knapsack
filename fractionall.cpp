
#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[100][100];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }

        }
    }

    return dp[n][W];
}

int main() {
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;
    int n = 3;

    cout << knapsack(W, wt, val, n);

    return 0;
}
