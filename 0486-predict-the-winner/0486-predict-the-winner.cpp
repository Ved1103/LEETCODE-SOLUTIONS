class Solution {
public:
    int helper(vector<int>&nums, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int front = nums[i]-helper(nums,i+1,j,dp);
        int back = nums[j] - helper(nums,i,j-1,dp);
        return dp[i][j]=max(front,back);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // int ans = helper(nums,0,n-1,dp);
        // if(ans>=0){
        //     return true;
        // }
        // return false;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                int front = nums[i] - dp[i + 1][j];
                int back = nums[j] - dp[i][j - 1];
                dp[i][j] = max(front, back);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};