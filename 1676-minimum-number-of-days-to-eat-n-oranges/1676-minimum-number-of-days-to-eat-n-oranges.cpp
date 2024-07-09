class Solution {
public:
    unordered_map<int, int> dp;  
    int helper(int oranges) {
        if (oranges < 2) return oranges; 
        if (dp.count(oranges)) return dp[oranges];  
        int pick = 1 + oranges % 2 + helper(oranges / 2);
        int notpick = 1 + oranges % 3 + helper(oranges / 3);
        dp[oranges] = min(pick, notpick);
        return dp[oranges];
    }

    int minDays(int n) {
        return helper(n);
    }
};