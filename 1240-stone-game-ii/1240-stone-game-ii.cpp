class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }
        
        return helper(0, 1, piles, dp, suffixSum);
    }
    
    int helper(int i, int M, vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffixSum) {
        int n = piles.size();
        if (i == n) return 0;
        if (2 * M >= n - i) return suffixSum[i];
        if (dp[i][M] != -1) return dp[i][M];
        
        int res = 0;
        for (int x = 1; x <= 2 * M; ++x) {
            res = max(res, suffixSum[i] - helper(i + x, max(M, x), piles, dp, suffixSum));
        }
        dp[i][M] = res;
        return dp[i][M];
    }
};
