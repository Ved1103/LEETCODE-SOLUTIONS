class Solution {
public:
    bool helper(const string& s1, const string& s2, unordered_map<string, bool>& dp) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        string key = s1 + s2;
        if (dp.find(key) != dp.end()) return dp[key];
        int n = s1.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; ++i) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) return dp[key] = false;
        }
        for (int i = 1; i < n; ++i) {
            if (helper(s1.substr(0, i), s2.substr(0, i), dp) && helper(s1.substr(i), s2.substr(i), dp)) 
                return dp[key] = true;
            if (helper(s1.substr(0, i), s2.substr(n - i), dp) && helper(s1.substr(i), s2.substr(0, n - i), dp)) 
                return dp[key] = true;
        }
        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        return helper(s1, s2, dp);
    }
};
