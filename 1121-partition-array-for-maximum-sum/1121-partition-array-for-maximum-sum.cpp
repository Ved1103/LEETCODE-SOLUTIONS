class Solution {
public:
    int helper(int i, vector<int>& arr, int n, int k, vector<int>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int max_sum = 0, max_val = 0, temp_len = 0;

        for (int j = i; j < min(i + k, n); j++) {
            temp_len++;
            max_val = max(max_val, arr[j]);
            max_sum = max(max_sum, max_val * temp_len + helper(j + 1, arr, n, k, dp));
        }

        dp[i] = max_sum;
        return dp[i];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int> dp(n, -1);
        // return helper(0, arr, n, k, dp);

        vector<int>dp(n+1,0);
        for (int i = 1; i <= n; ++i) {
            int max_val = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                max_val = max(max_val, arr[i - j]);  
                dp[i] = max(dp[i], dp[i - j] + max_val * j);  
            }
        }
        
        return dp[n];  
    }
};
