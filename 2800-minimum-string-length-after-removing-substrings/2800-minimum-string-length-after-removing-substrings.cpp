class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty()) {
                st.push(ch);
                continue;
            }
            if (ch == 'B' and st.top() == 'A') {
                st.pop();
            } 
            else if (ch == 'D' and st.top() == 'C') {
                st.pop();
            } 
            else {
                st.push(ch);
            }
        }
        return st.size();
    }
};