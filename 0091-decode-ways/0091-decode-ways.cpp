class Solution {
public:
    int helper(int i, string &s, vector<int>& dp, int n) {
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        // Take single digit
        int takesingle = helper(i + 1, s, dp, n);

        int takedouble = 0;
        // Take double digits 
        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            takedouble = helper(i + 2, s, dp, n);
        }

        return dp[i] = takesingle + takedouble;
    }

    int numDecodings(string s) {
        int n = s.size();
        // vector<int> dp(n, -1);
        // return helper(0, s, dp, n);
        if(n==0 ||s[0]=='0'){
            return 0;
        }
        vector<int>dp(n+1,0);
        dp[n]=1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                dp[i] += dp[i + 1];
            }
            if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
        

    }
};
