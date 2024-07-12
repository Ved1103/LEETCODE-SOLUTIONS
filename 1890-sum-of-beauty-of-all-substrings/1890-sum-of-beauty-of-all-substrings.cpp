class Solution {
public:
    int beautySum(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; ++j) {
                freq[s[j]]++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto p : freq) {
                    maxFreq = max(maxFreq, p.second);
                    minFreq = min(minFreq, p.second);
                }
                res += maxFreq - minFreq;
            }
        }
        return res;
    }
};
