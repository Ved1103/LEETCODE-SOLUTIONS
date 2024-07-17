// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (int num : nums) {
//             sum += num;
//         }

//         // If the total sum is odd, it's not possible to partition it into two equal subsets
//         if (sum % 2 != 0) {
//             return false;
//         }

//         int target = sum / 2;
//         vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
//         return canPartitionRecursive(nums, target, 0, memo);
//     }

// private:
//     bool canPartitionRecursive(vector<int>& nums, int target, int currentIndex, vector<vector<int>>& memo) {
//         // Base cases
//         if (target == 0) return true;
//         if (currentIndex >= nums.size() || target < 0) return false;

//         // Check if the solution is already computed
//         if (memo[currentIndex][target] != -1) {
//             return memo[currentIndex][target] == 1;
//         }

//         // Include the number at the current index
//         bool include = canPartitionRecursive(nums, target - nums[currentIndex], currentIndex + 1, memo);
        
//         // Exclude the number at the current index
//         bool exclude = canPartitionRecursive(nums, target, currentIndex + 1, memo);
        
//         // Store the result in memo and return
//         memo[currentIndex][target] = (include || exclude) ? 1 : 0;
//         return memo[currentIndex][target] == 1;
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true; 
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};

