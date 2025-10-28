// DAILY TEMPERATURE
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(const vector<int>& T) {
    int n = (int)T.size();
    vector<int> ans(n, 0);
    stack<int> st; // indices with unresolved warmer day
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && T[i] > T[st.top()]) {
            int j = st.top(); st.pop();
            ans[j] = i - j;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    vector<int> ans = dailyTemperatures(t);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
