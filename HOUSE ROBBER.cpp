//HOUSE ROBBER
#include <bits/stdc++.h>
using namespace std;

int rob(const vector<int>& nums) {
    int prev2 = 0, prev1 = 0;          // Why: rolling DP for O(1) space
    for (int x : nums) {
        int take = prev2 + x;
        int skip = prev1;
        int cur = max(take, skip);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    cout << rob(nums) << "\n";
    return 0;
}
