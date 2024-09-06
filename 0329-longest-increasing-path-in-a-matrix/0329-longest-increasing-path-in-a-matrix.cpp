class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int max_len = 1;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                max_len = max(max_len, 1 + dfs(ni, nj, dp, matrix, n, m));
            }
        }

        dp[i][j] = max_len;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, dp, matrix, n, m));
            }
        }
        return ans;
    }
};
