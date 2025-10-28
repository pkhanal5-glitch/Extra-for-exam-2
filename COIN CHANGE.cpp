//COIN CHANGE
#include <bits/stdc++.h>
using namespace std;

int coinChange(const vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    const int INF = amount + 1;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int c : coins) {
        if (c <= 0) continue;                  // Why: guard invalid coin input
        for (int x = c; x <= amount; ++x) {
            if (dp[x - c] != INF) dp[x] = min(dp[x], dp[x - c] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if (!(cin >> n)) return 0;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    int amount; 
    cin >> amount;

    cout << coinChange(coins, amount) << "\n";
    return 0;
}
