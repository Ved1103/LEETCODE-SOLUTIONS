class Solution {
public:
    int helper(int ind, vector<int>& days, vector<int>& costs, int n, vector<int>& dp) {
        if (ind >= n) {
            return 0;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }

        // for taking 1 day ticket
        int temp1 = costs[0] + helper(ind + 1, days, costs, n, dp);

        // for taking 7 day ticket
        int j = ind;
        while (j < n && days[j] < days[ind] + 7) {
            j++;
        }
        int temp2 = costs[1] + helper(j, days, costs, n, dp);

        // for taking 30 day ticket
        j = ind;
        while (j < n && days[j] < days[ind] + 30) {
            j++;
        }
        int temp3 = costs[2] + helper(j, days, costs, n, dp);

        dp[ind] = min({temp1, temp2, temp3});
        return dp[ind];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1); 
        return helper(0, days, costs, n, dp);
    }
};
