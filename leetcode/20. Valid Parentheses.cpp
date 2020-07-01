class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> matching = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (!st.empty() && matching[c] == st.top()) {
                st.pop();
            } else {
                return false;
            }
            return st.empty();
        }
    };
}
