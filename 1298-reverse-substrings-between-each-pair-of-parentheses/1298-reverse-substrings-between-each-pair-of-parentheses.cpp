class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                string reversed = "";
                while (!st.empty() && st.top() != '(') {
                    reversed += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
                for (char rc : reversed) {
                    st.push(rc);
                }
            } else {
                st.push(ch);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
