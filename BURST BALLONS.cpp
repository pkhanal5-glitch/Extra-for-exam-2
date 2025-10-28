// BRUST BALLONS
#include <bits/stdc++.h>
using namespace std;

long long maxCoinsBurstBalloons(const vector<int>& nums) {
    const int n = (int)nums.size();
    vector<int> val(n + 2, 1);
    for (int i = 0; i < n; ++i) val[i + 1] = nums[i];

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));

    // Why: choose the last balloon k for each open interval (l, r)
    for (int len = 2; len <= n + 1; ++len) {       // interval width
        for (int l = 0; l + len <= n + 1; ++l) {
            int r = l + len;
            long long best = 0;
            for (int k = l + 1; k <= r - 1; ++k) {
                long long gain = 1LL * val[l] * val[k] * val[r];
                best = max(best, dp[l][k] + gain + dp[k][r]);
            }
            dp[l][r] = best;
        }
    }
    return dp[0][n + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    cout << maxCoinsBurstBalloons(nums) << '\n';
    return 0;
}
