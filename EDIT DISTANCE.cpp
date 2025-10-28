//EDIT DISTANCE
#include <bits/stdc++.h>
using namespace std;

int minDistance(const string& a, const string& b) {
    const int m = (int)a.size(), n = (int)b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i; // deletions
    for (int j = 0; j <= n; ++j) dp[0][j] = j; // insertions

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Why: 1 op + best among replace, delete, insert
                dp[i][j] = 1 + min({dp[i - 1][j - 1], // replace
                                    dp[i - 1][j],     // delete
                                    dp[i][j - 1]});   // insert
            }
        }
    }
    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string w1, w2;
    if (!(cin >> w1)) return 0;
    cin >> w2;

    cout << minDistance(w1, w2) << '\n';
    return 0;
}
