/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
//  */

// Using Two pointer approach and traversal O(N^2) T.C 
// class Solution {
// private:
//     int dfs(TreeNode* root, int targetSum) {
//         if (!root) return 0;
//         int ans = 0;
//         if (root->val == targetSum) {
//             ans++;
//         }
//         ans += dfs(root->left, targetSum - root->val);
//         ans += dfs(root->right, targetSum - root->val);
//         return ans;
//     }

// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         if (root == nullptr) return 0;
//         int ans = dfs(root, targetSum);
//         ans += pathSum(root->left, targetSum);
//         ans += pathSum(root->right, targetSum);
//         return ans;
//     }
// };

// Using prefix sum and hashmap { same as number of subarrays with sum equals K}
class Solution {
private:
    int dfs(TreeNode* root, int targetSum, long long currentSum, unordered_map<long long, int>& prefixSums) {
        if (!root) return 0;
        currentSum += root->val;
        int numPaths = 0;
        if (prefixSums.find(currentSum - targetSum) != prefixSums.end()) {
            numPaths += prefixSums[currentSum - targetSum];
        }
        prefixSums[currentSum]++;
        numPaths += dfs(root->left, targetSum, currentSum, prefixSums);
        numPaths += dfs(root->right, targetSum, currentSum, prefixSums);
        prefixSums[currentSum]--;
        return numPaths;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1;
        return dfs(root, targetSum, 0, prefixSums);
    }
};
