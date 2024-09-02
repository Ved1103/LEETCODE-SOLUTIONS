class Solution {
public:
    int helper(int i, vector<int>& nums, vector<vector<int>>& dp, bool isUp) {
        if (i >= nums.size()) return 0;
        if (dp[i][isUp] != -1) return dp[i][isUp];

        int notTake = helper(i + 1, nums, dp, isUp);
        int take = 0;

        if (isUp) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                take = 1 + helper(i + 1, nums, dp, !isUp);
            }
        } else {
            if (i == 0 || nums[i] < nums[i - 1]) {
                take = 1 + helper(i + 1, nums, dp, !isUp);
            }
        }

        dp[i][isUp] = max(take, notTake);
        return dp[i][isUp];
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return max(helper(0, nums, dp, true), helper(0, nums, dp, false));
    }
};
