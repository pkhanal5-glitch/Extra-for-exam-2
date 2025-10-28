// sliding window maximum
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    const int n = (int)nums.size();
    if (k == 1) return nums;

    deque<int> dq;              // stores indices; values in decreasing order
    vector<int> ans;
    ans.reserve(n - k + 1);

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); // Why: dominated
        dq.push_back(i);
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();          // Why: out of window
        if (i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    vector<int> res = maxSlidingWindow(nums, k);
    for (int i = 0; i < (int)res.size(); ++i) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
    return 0;
}
