class Solution {
public:
    int helper(int i, bool canBuy, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];

        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, false, prices, dp);
            int skip = helper(i + 1, true, prices, dp);
            dp[i][canBuy] = max(buy, skip);
        } else {
            int sell = prices[i] + helper(i + 1, true, prices, dp);
            int skip = helper(i + 1, false, prices, dp);
            dp[i][canBuy] = max(sell, skip);
        }

        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return helper(0, true, prices, dp);
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max((-prices[i] + dp[i + 1][0]), 0 + dp[i + 1][1]);
                } else {
                    profit = max((prices[i] + dp[i + 1][1]), 0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
