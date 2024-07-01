class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                if (count == 1) {
                    return false;
                }
                if (i >= 2 && nums[i] <= nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }
                count++;
            }
        }
        return true;
    }
};