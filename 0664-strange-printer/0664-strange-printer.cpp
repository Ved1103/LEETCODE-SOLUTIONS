class Solution {
public:
    int solve(string s, int left, int right, vector<vector<int>>& dp) {
        if (left == right) {
            return 1;
        }
        if (left > right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int i = left;
        while (i <= right && s[i] == s[left]) {
            i++;
        }
        if (i > right) {
            return dp[left][right] = 1;
        }

        int stringBreak = 1 + solve(s, i, right, dp);

        int stringNotBreak = INT_MAX;
        for (int j = i; j <= right; j++) {
            if (s[j] == s[left]) {
                stringNotBreak =
                    min(stringNotBreak,
                        solve(s, i, j - 1, dp) + solve(s, j, right, dp));
            }
        }

        return dp[left][right] = min(stringNotBreak, stringBreak);
    }

    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};