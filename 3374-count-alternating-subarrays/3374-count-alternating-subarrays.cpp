class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        long long i = 0;
        
        for (long long j = 1; j < n; ++j) {
            if (nums[j] == nums[j - 1]) {
                i = j;
            }
            count += j - i + 1;
        }
        
        return count+1;
    }
};
