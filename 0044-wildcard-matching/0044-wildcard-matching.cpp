class Solution {
public:
    bool helper(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false; // s has to be all stars for empty seq
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        } else if (p[j] == '*') {
            dp[i][j] = helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
        } else {
            dp[i][j] = false;
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return helper(n - 1, m - 1, s, p, dp);
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
