class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&dp,vector<vector<int>>& dungeon,int n, int m){
        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(i==n-1 and j==m-1){// we reached the queen
            return max(1,1-dungeon[i][j]);
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int right = helper(i,j+1,dp,dungeon,n,m);
        int down = helper(i+1,j,dp,dungeon,n,m);
        int req_health = min(right, down) - dungeon[i][j];
        dp[i][j] = max(1, req_health);
        return dp[i][j];

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return helper(0,0,dp,dungeon,n,m);
        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[n-1][m-1] = max(1, 1 - dungeon[n-1][m-1]);
        for (int j = m - 2; j >= 0; --j) {
            dp[n-1][j] = max(1, dp[n-1][j+1] - dungeon[n-1][j]);
        }

        for (int i = n - 2; i >= 0; --i) {
            dp[i][m-1] = max(1, dp[i+1][m-1] - dungeon[i][m-1]);
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = m - 2; j >= 0; --j) {
                int min_health_on_exit = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, min_health_on_exit - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};