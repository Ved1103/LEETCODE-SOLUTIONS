class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int,int> list;
        int res = 0;
        for(auto val: nums) list[val]++;
        for(auto val: nums) {
            list[val]--;
            res += list[val+k] + list[val-k];
        }
        return res;
    }
};