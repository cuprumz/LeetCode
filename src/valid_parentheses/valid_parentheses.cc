#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == '{' || ch == '(' || ch == '[') {
                st.push(ch);
            } else if (ch == '}' || ch == ')' || ch == ']') {
                if (st.empty()) return false;
                char top = st.top();
                if ((top == '{' && ch == '}') ||
                    (top == '(' && ch == ')') ||
                    (top == '[' && ch == ']')) {
                    st.pop();
                }
            } else {
                return false;
            }
        }
        return st.empty();
    }
};

int main(int argc, char **argv) {

    string s = "{[]}}";

    if (argc > 1) {
        s = argv[1];
    }

    Solution solution;

    cout << "string = \"" << (s) << "\"" << endl;
    cout << solution.isValid(s) << endl;


    return 0;
}
