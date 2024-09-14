//bruteforce O(n*n)
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int ans = 1, maxval = 0, n = nums.size();
//         for(int i = 0; i < n; i++) {
//             int temp = nums[i];
//             for(int j = i; j < n; j++) {
//                 temp &= nums[j];
//                 if(temp > maxval) {
//                     maxval = temp;
//                     ans = j - i + 1;
//                 } else if(temp == maxval) {
//                     ans = max(ans, j - i + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };


// optimised
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxval = *max_element(nums.begin(), nums.end());
        int ans = 0, currentLength = 0;
        for (int num : nums) {
            if (num == maxval) {
                currentLength++;
                ans = max(ans, currentLength);
            } else {
                currentLength = 0;
            }
        }
        return ans;
    }
};

