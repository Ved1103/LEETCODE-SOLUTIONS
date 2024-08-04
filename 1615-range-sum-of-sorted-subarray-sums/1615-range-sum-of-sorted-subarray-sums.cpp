class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        int size = n * (n + 1) / 2;
        vector<int> subarray_sum(size);

        int index = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                subarray_sum[index++] = sum;
            }
        }

        sort(subarray_sum.begin(), subarray_sum.end());

        for (int i = left - 1; i < right; i++) {
            ans = (ans + subarray_sum[i]) % MOD;
        }
        return ans;
    }
};
