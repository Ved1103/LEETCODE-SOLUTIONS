// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> st;
//         st.push(-1);
//         int maxLen = 0;
//         int n = s.size();

//         for (int i = 0; i < n; i++) {
//             char ch = s[i];
//             if (ch == '(') {
//                 st.push(i);
//             } else {
//                 st.pop();
//                 if (st.empty()) {
//                     st.push(i);
//                 } else {
//                     maxLen = max(maxLen, i - st.top());
//                 }
//             }
//         }

//         return maxLen;
//     }
// };
class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int maxLen = 0;
        int n = s.size();

        // Left to right traversal
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                close++;
            }
            if (open == close) {
                maxLen = max(maxLen, 2 * close);
            } else if (close > open) {
                open = close = 0;
            }
        }

        open = close = 0;
        // Right to left traversal
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                close++;
            }
            if (open == close) {
                maxLen = max(maxLen, 2 * open);
            } else if (open > close) {
                open = close = 0;
            }
        }

        return maxLen;
    }
};
