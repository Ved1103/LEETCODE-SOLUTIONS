class Solution {
public:
    int helper(int ind, vector<int>& nums, int k, int n, unordered_map<int,int>& mp) {
        if(ind == n) {
            return 1;
        }
        
        // Not take
        int notTake = helper(ind+1, nums, k, n, mp);

        // Check if we can take
        bool canTake = true;
        if(mp[nums[ind] - k] > 0 || mp[nums[ind] + k] > 0) {
            canTake = false;
        }

        int take = 0;
        if(canTake) {
            mp[nums[ind]]++;
            take = helper(ind+1, nums, k, n, mp);
            mp[nums[ind]]--;  
        }

        return notTake + take;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        return helper(0, nums, k, n, mp) - 1;  
    }
};
