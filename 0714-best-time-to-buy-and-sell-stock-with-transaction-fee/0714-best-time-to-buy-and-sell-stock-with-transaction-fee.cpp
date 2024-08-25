class Solution {
public:
    int helper(int i, bool canBuy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];
        
        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, false, prices, fee, dp);
            int skip = helper(i + 1, true, prices, fee, dp);
            dp[i][canBuy] = max(buy, skip);
        } else {
            int sell = prices[i] - fee + helper(i + 1, true, prices, fee, dp);
            int skip = helper(i + 1, false, prices, fee, dp);
            dp[i][canBuy] = max(sell, skip);
        }
        
        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, true, prices, fee, dp);
    }
};
