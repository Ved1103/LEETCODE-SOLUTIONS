class Solution {
public:
    int func(vector<vector<int>>&dp, int i, int j){
        //base case
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        //conditions
        int up = func(dp,i-1,j);
        int down = func(dp,i,j-1);
        return dp[i][j] = up + down;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return func(dp,m-1,n-1);
    }
};