class Solution {
public:
    int helper(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp) {
        if (curr == nums.size()) return 0;
        if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];
        
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + helper(curr, curr + 1, nums, dp);
        }
        int notTake = helper(prev, curr + 1, nums, dp);
        
        dp[prev + 1][curr] = max(take, notTake);
        return dp[prev + 1][curr];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        // return helper(-1, 0, nums, dp);
        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
