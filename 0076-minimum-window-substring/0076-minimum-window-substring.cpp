class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";
        
        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }
        
        int i = 0, j = 0;
        int minlength = INT_MAX;
        int start = 0;
        int count = 0;
        unordered_map<char, int> temp;
        
        while (j < n) {
            temp[s[j]]++;
            
            if (mp.find(s[j]) != mp.end() && temp[s[j]] <= mp[s[j]]) {
                count++;
            }
            
            while (count == m) {
                if (j - i + 1 < minlength) {
                    minlength = j - i + 1;
                    start = i;
                }
                
                temp[s[i]]--;
                if (mp.find(s[i]) != mp.end() && temp[s[i]] < mp[s[i]]) {
                    count--;
                }
                i++;
            }
            j++;
        }
        
        return (minlength == INT_MAX) ? "" : s.substr(start, minlength);
    }
};
