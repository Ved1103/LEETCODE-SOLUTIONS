class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> st;
        if (x > y) {
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && st.top() == 'a' && s[i] == 'b') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            string temp = "";
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++) {
                if (!st.empty() && st.top() == 'b' && temp[i] == 'a') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(temp[i]);
                }
            }
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            string temp = "";
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++) {
                if (!st.empty() && st.top() == 'a' && temp[i] == 'b') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(temp[i]);
                }
            }
        }
        return ans;
    }
};
