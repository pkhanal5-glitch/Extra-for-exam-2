//Min Stack-medium
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> vals_, mins_;
public:
    MinStack() = default;

    void push(int val) {
        vals_.push(val);
        // Why: maintain the min seen so far at each depth
        if (mins_.empty() || val <= mins_.top()) mins_.push(val);
    }

    void pop() {
        if (vals_.top() == mins_.top()) mins_.pop(); // Why: min element leaving
        vals_.pop();
    }

    int top() const { return vals_.top(); }

    int getMin() const { return mins_.top(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << "\n"; // -3
    minStack.pop();
    cout << minStack.top() << "\n";    // 0
    cout << minStack.getMin() << "\n"; // -2
    return 0;
}
