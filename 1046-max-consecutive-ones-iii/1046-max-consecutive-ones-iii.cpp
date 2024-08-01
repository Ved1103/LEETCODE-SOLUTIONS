class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int max_len = 0;
        int zero_count = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                zero_count++;
            }

            while (zero_count > k) {
                if (nums[i] == 0) {
                    zero_count--;
                }
                i++;
            }

            max_len = max(max_len, j - i + 1);
            j++;
        }

        return max_len;
    }
};
