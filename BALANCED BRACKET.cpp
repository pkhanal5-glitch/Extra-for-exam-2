//balanced bracket
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a string of brackets is balanced
string isBalanced(const string& s) {
    stack<char> st;

    for (char ch : s) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // For closing brackets, check if they match the top of the stack
        else {
            if (st.empty()) return "NO"; // No matching opening bracket

            char top = st.top();
            st.pop();

            // Check for correct matching pair
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return "NO";
            }
        }
    }

    // If stack is empty, all brackets matched correctly
    return st.empty() ? "YES" : "NO";
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    cin.ignore(); // Clear newline from input buffer

    for (int i = 0; i < n; ++i) {
        string s;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, s);

        cout << isBalanced(s) << endl;
    }

    return 0;
}
