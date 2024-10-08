class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int maxgap = INT_MIN;
        for (int i = 1; i < n; i++) {
            int temp = nums[i] - nums[i - 1];
            maxgap = max(maxgap, temp);
        }
        return maxgap;
    }
};