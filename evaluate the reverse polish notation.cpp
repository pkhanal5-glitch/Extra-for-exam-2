//evaluate the reverse polish notation
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    // Function to evaluate Reverse Polish Notation
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            // If the token is an operator, pop two operands and apply the operation
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // Integer division truncates toward zero
            } else {
                // If the token is a number, convert and push it
                st.push(stoi(token));
            }
        }

        // Final result is on top of the stack
        return st.top();
    }
};

int main() {
    Solution sol;
    vector<string> tokens;
    string input;

    cout << "Enter RPN tokens one by one (type 'end' to finish):\n";
    while (cin >> input && input != "end") {
        tokens.push_back(input);
    }

    int result = sol.evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
