#include<string>
#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            string copy = it;
            sort(copy.begin(),copy.end());
            mp[copy].push_back(it);
        }

        vector<vector<string>>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};