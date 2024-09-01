class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftSum = 0, rightSum = 0, maxSum = 0;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            leftSum += nums[i];
        }
        maxSum = leftSum;
        int rightIndex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= nums[i];
            rightSum += nums[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};

// dp soln but giving tle due to large size of n
// class Solution {
// public:
//     int dp[10001][10001];
//     int solve(vector<int>& cardPoints, int i, int j, int k) {
//         if (k == 0) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
        
//         int takeLeft = cardPoints[i] + solve(cardPoints, i + 1, j, k - 1);
//         int takeRight = cardPoints[j] + solve(cardPoints, i, j - 1, k - 1);
        
//         return dp[i][j] = max(takeLeft, takeRight);
//     }
    
//     int maxScore(vector<int>& cardPoints, int k) {
//         memset(dp, -1, sizeof(dp));
//         int n = cardPoints.size();
//         return solve(cardPoints, 0, n - 1, k);
//     }
// };
