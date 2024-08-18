class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int currentSum = 0, splits = 1;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                splits++;
                currentSum = num;
                if (splits > k)
                    return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = *max_element(nums.begin(), nums.end());
        int j = 0;
        for (int num : nums) {
            j += num;
        }

        while (i < j) {
            int mid = i + (j - i) / 2;
            if (canSplit(nums, k, mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};