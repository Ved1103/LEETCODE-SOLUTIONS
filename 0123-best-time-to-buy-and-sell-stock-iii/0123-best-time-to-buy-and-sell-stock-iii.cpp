class Solution {
public:
    int helper(int i, bool canBuy, int transactionsLeft, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (i == n || transactionsLeft == 0) return 0;

        if (dp[i][canBuy][transactionsLeft] != -1) return dp[i][canBuy][transactionsLeft];

        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, false, transactionsLeft, prices, n, dp);
            int skip = helper(i + 1, true, transactionsLeft, prices, n, dp);
            dp[i][canBuy][transactionsLeft] = max(buy, skip);
        } else {
            int sell = prices[i] + helper(i + 1, true, transactionsLeft - 1, prices, n, dp);
            int skip = helper(i + 1, false, transactionsLeft, prices, n, dp);
            dp[i][canBuy][transactionsLeft] = max(sell, skip);
        }

        return dp[i][canBuy][transactionsLeft];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, true, 2, prices, n, dp);
    }
};
