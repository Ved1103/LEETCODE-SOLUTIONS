class Solution {
public:
    int minLength(string s) {
        // stack<char> st;
        // for (char ch : s) {
        //     if (st.empty()) {
        //         st.push(ch);
        //         continue;
        //     }
        //     if (ch == 'B' and st.top() == 'A') {
        //         st.pop();
        //     } 
        //     else if (ch == 'D' and st.top() == 'C') {
        //         st.pop();
        //     } 
        //     else {
        //         st.push(ch);
        //     }
        // }
        // return st.size();

        int n = s.size();
        int i = 0;

        for (int j = 0; j < n; ++j) {
            s[i] = s[j];
            if (i >= 1 && ((s[i] == 'B' && s[i-1] == 'A') || (s[i] == 'D' && s[i-1] == 'C'))) {
                i -= 2;
            }
            i++;
        }
        
        return i;

    }
};