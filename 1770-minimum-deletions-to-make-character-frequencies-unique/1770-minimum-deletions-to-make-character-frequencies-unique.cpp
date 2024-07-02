class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> st;
        unordered_map<int, int> mp;
        for (auto it : s) {
            mp[it - 'a']++;
        }
        int count = 0;
        for (auto it : mp) {
            int freq = it.second;
            while (freq > 0 && st.count(freq)) {
                count++;
                freq--;
            }
            st.insert(freq);
        }
        return count;
    }
};