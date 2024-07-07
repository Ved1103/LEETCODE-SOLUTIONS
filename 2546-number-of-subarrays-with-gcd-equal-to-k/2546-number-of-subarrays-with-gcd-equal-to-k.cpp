class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            if (temp % k == 0) {
                if (temp == k) count++;
                for (int j = i + 1; j < n; j++) {
                    temp = gcd(temp, nums[j]);
                    if (temp == k) count++;
                    else if (temp < k) break;
                }
            }
        }
        return count;
    }
};