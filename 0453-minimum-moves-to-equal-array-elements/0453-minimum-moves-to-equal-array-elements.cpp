class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += nums[i]-nums[0];
        }
        return ans;
    }
};
// dp approach only if nums[i]>0
// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int n = nums.size();
//         int minNum = *min_element(nums.begin(), nums.end());
//         int dp[n][minNum + 1];
        
//         for (int j = 0; j <= minNum; j++) {
//             dp[0][j] = abs(nums[0] - j);
//         }

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j <= minNum; j++) {
//                 dp[i][j] = dp[i-1][j] + abs(nums[i] - j);
//             }
//         }

//         int ans = 1e9;
//         for (int j = 0; j <= minNum; j++) {
//             ans = min(ans, dp[n-1][j]);
//         }

//         return ans;
//     }
// };