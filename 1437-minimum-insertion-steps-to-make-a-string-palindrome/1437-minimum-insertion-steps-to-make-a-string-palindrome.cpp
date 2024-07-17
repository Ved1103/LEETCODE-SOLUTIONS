class Solution {
public:
    int helper(string &s, int start, int end, vector<vector<int>> &dp) {
        if (start >= end) return 0;
        if (dp[start][end] != -1) return dp[start][end];

        if (s[start] == s[end]) {
            dp[start][end] = helper(s, start + 1, end - 1, dp);
        } else {
            int insertLeft = 1 + helper(s, start + 1, end, dp);
            int insertRight = 1 + helper(s, start, end - 1, dp);
            dp[start][end] = min(insertLeft, insertRight);
        }

        return dp[start][end];
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, dp);
    }
};
