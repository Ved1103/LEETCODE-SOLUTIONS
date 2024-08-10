class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int i = 0, j = 0;
        int currentSum = 0;

        while (j < n) {
            currentSum += nums[j];
            while (currentSum >= target) {
                minLength = min(minLength, j - i + 1);
                currentSum -= nums[i];
                i++;
            }
            j++;
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
