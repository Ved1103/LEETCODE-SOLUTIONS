class Solution {
public:
    int helper(int ind, int n, string &s, unordered_set<string> &st, vector<int> &dp) {
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];
        
        int extraChars = 1 + helper(ind + 1, n, s, st, dp);
        
        for (int i = ind; i < n; i++) {
            string substr = s.substr(ind, i - ind + 1);
            if (st.find(substr) != st.end()) {
                extraChars = min(extraChars, helper(i + 1, n, s, st, dp));
            }
        }
        
        return dp[ind] = extraChars;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for (auto word : dictionary) {
            st.insert(word);
        }

        int n = s.size();
        vector<int> dp(n, -1);

        return helper(0, n, s, st, dp);
    }
};
