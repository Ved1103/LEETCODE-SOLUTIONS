class Solution {
public:
    // bool isPalindrome(string& temp) {
    //     int len = temp.size();
    //     for (int i = 0; i < len / 2; i++) {
    //         if (temp[i] != temp[len - i - 1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int helper(int ind, string s, int n, vector<int> dp) {
    //     if (ind == n) {
    //         return 0;
    //     }

    //     if (dp[ind] != -1)
    //         return dp[ind];
    //     string temp = "";
    //     int ans = INT_MAX;
    //     for (int j = ind; j < n; j++) {
    //         temp += s[j];

    //         if (isPalindrome(temp)) {
    //             int cost = 1 + helper(j + 1, s, n, dp);
    //             ans = min(cost, ans);
    //         }
    //     }
    //     dp[ind] = ans;
    //     return ans;
    // }
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        // vector<int> dp(n+1, -1);
        // return helper(0, s, n, dp) - 1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1; // Base case: No cuts needed for an empty string

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPalindrome(s, j, i - 1)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
