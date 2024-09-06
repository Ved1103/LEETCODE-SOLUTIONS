class Solution {
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            dp[i][j] = (helper(i, j + 2, s, p, dp) || (match && helper(i + 1, j, s, p, dp)));
        } else {
            dp[i][j] = (match && helper(i + 1, j + 1, s, p, dp));
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, s, p, dp);
    }
};
