class Solution {
public:
    int func(vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid, int i, int j) {
        // Base cases
        if (i == 0 && j == 0) return obstacleGrid[i][j] == 0 ? 1 : 0;
        if (i < 0 || j < 0) return 0;
        if (obstacleGrid[i][j] == 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
    
        int up = func(dp, obstacleGrid, i - 1, j);
        int left = func(dp, obstacleGrid, i, j - 1);
        
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(dp, obstacleGrid, m - 1, n - 1);
    }
};
