class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;
        for (auto it : edges) {
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int ans = 0;
        int count = 0;
        for (auto it : mp) {
            if (count < it.second) {
                count = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};