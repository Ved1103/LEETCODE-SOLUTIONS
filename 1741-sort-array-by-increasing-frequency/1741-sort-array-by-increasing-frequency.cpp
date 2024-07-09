class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        auto cmp = [&mp](int x, int y) {
            if (mp[x] == mp[y])
                return x > y;
            else
                return mp[x] < mp[y];
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};