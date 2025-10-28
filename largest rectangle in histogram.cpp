// LARGEST RECTANGLE IN HISTOGRAM
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(const vector<int>& heights) {
    const int n = (int)heights.size();
    long long best = 0;
    vector<int> st; st.reserve(n);

    for (int i = 0; i <= n; ++i) {
        int cur = (i < n ? heights[i] : 0);      // Why: sentinel to process remaining bars
        while (!st.empty() && heights[st.back()] > cur) {
            int h = heights[st.back()]; st.pop_back();
            int left = st.empty() ? -1 : st.back();  // Why: previous smaller index
            long long width = i - left - 1;          // Why: next smaller at i
            best = max(best, 1LL * h * width);
        }
        st.push_back(i);
    }
    return (int)best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) cin >> heights[i];

    cout << largestRectangleArea(heights) << "\n";
    return 0;
}
