// // recusion approach but is giving TLE due to O(n^2)  time complexity
// class Solution {
// public:
//     int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();
//         int result = helper(nums, x, 0, n - 1);
//         return result == INT_MAX ? -1 : result;
//     }

// private:
//     int helper(vector<int>& nums, int x, int left, int right) {
//         if (x == 0) {
//             return 0;
//         }
//         if (x < 0 || left > right) {
//             return INT_MAX;
//         }
//         int removeLeft = helper(nums, x - nums[left], left + 1, right);
//         if (removeLeft != INT_MAX) {
//             removeLeft += 1;
//         }
//         int removeRight = helper(nums, x - nums[right], left, right - 1);
//         if (removeRight != INT_MAX) {
//             removeRight += 1;
//         }
//         return min(removeLeft, removeRight);
//     }
// };



//here the logic is to focus on the finding a subarray which has sum equal to sum-x so that the sum of remaning other elements in x and they are minimum in amount. so we apply the same concept as maximum subaaray sum equals k and use prefix sum + hashmap
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x)
            return -1;
        int restSum = sum-x;
        int longest = INT_MIN;
        sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(mp.count(sum-restSum)) {
                longest = max(longest, i-mp[sum-restSum]);
            }
        }
        return longest==INT_MIN?-1:n-longest;
    }
};