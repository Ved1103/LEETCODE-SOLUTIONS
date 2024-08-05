// class Solution {
// public:
//     bool checkValidString(string s) {
//         stack<int> open, star; 
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '(') {
//                 open.push(i);
//             } else if (s[i] == '*') {
//                 star.push(i);
//             } else {
//                 if (!open.empty()) {
//                     open.pop();
//                 } else if (!star.empty()) {
//                     star.pop();
//                 } else {
//                     return false;
//                 }
//             }
//         }
//         while (!open.empty() && !star.empty()) {
//             if (open.top() > star.top()) {
//                 return false;
//             }
//             open.pop();
//             star.pop();
//         }
//         return open.empty();
//     }
// };
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }
            if (open < 0) {
                return false;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }
            if (close < 0) {
                return false;
            }
        }
        return true;
    }
};