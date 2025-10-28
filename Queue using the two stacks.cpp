//Queue using the two stacks-medium
// File: src/two_stacks_queue.cpp
#include <bits/stdc++.h>
using namespace std;

class Queue2Stacks {
    stack<int> in_, out_;
    // Why: move cost paid rarely; makes each op amortized O(1)
    void shift() {
        if (out_.empty()) {
            while (!in_.empty()) {
                out_.push(in_.top());
                in_.pop();
            }
        }
    }
public:
    void push(int x) { in_.push(x); }
    void pop() { shift(); out_.pop(); }
    int front() { shift(); return out_.top(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;

    Queue2Stacks q2s;
    for (int i = 0; i < q; ++i) {
        int type; 
        cin >> type;
        if (type == 1) {
            int x; cin >> x;
            q2s.push(x);
        } else if (type == 2) {
            q2s.pop();
        } else if (type == 3) {
            cout << q2s.front() << '\n';
        }
    }
    return 0;
}
