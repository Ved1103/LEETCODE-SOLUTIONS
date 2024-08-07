class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); 
        int maxLen = 0; 
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); 
                } else {
                    maxLen = max(maxLen, i - st.top()); 
                }
            }
        }
        
        return maxLen;
    }
};
