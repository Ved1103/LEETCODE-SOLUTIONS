class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0)
            return 0;
        
        // Optimization for large k
        // if (k >= n / 2) {
        //     int maxProfit = 0;
        //     for(int i = 1; i < n; i++)
        //         if(prices[i] > prices[i - 1])
        //             maxProfit += prices[i] - prices[i - 1];
        //     return maxProfit;
        // }
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                for(int transactionsLeft = 1; transactionsLeft <= k; transactionsLeft++) {
                    if(canBuy) {
                        int buy = -prices[i] + dp[i + 1][0][transactionsLeft];
                        int skip = dp[i + 1][1][transactionsLeft];
                        dp[i][canBuy][transactionsLeft] = max(buy, skip);
                    } else {
                        int sell = prices[i] + dp[i + 1][1][transactionsLeft - 1];
                        int skip = dp[i + 1][0][transactionsLeft];
                        dp[i][canBuy][transactionsLeft] = max(sell, skip);
                    }
                }
            }
        }
        
        return dp[0][1][k];
    }
};
