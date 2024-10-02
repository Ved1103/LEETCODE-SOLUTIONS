class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;
        
        for (int i = 0; i < temp.size(); i++) {
            if (rank.find(temp[i]) == rank.end()) {
                rank[temp[i]] = r++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(rank[arr[i]]);
        }

        return ans;
    }
};
