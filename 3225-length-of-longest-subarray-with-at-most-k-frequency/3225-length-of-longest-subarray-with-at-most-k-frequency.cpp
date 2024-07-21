class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = INT_MIN;
        int start = 0, end = 0;
        unordered_map<int, int> mp;
        while (end < n) {
            mp[nums[end]]++;
            while (mp[nums[end]] > k and start <= end) {
                mp[nums[start]]--;
                start++;
            }
            int temp = end - start + 1;
            maxlen = max(maxlen,temp);
            end++;
        }

        return maxlen;
    }
};