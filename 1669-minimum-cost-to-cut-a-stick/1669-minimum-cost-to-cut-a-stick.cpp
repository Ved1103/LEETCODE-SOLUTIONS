class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return minCostHelper(cuts, 0, m - 1, dp);
    }

private:
    int minCostHelper(vector<int>& cuts, int left, int right, vector<vector<int>>& dp) {
        if (right - left <= 1) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int minCost = INT_MAX;

        for (int i = left + 1; i < right; i++) {
            int cost = cuts[right] - cuts[left] + minCostHelper(cuts, left, i, dp) + minCostHelper(cuts, i, right, dp);
            minCost = min(minCost, cost);
        }

        dp[left][right] = minCost;
        return dp[left][right];
    }
};
