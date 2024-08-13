class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp;
        for (char ch : p) {
            mp[ch]++;
        }
        
        int i = 0, j = 0, n = s.size(), k = p.size();
        unordered_map<char, int> temp;
        
        while (j < n) {
            temp[s[j]]++;
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                if (temp == mp) {
                    ans.push_back(i); // same anagram mil gya yaha pe
                }
                temp[s[i]]--; // window size age badha rhe yaha
                if (temp[s[i]] == 0) {
                    temp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};
