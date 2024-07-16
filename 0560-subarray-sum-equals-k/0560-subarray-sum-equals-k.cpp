class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[sum] = 1;
        for (int num : nums) {
            sum += num;
            int find = sum - k;
            if (mp.count(find)) {
                count += mp[find];
            }
            mp[sum]++;
        }
        return count;
    }
};