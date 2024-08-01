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
 */

class Solution {
private:
    void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            result.push_back(path);
        } else {
            // Recur for left and right subtrees
            helper(root->left, targetSum, path, result);
            helper(root->right, targetSum, path, result);
        }
        // Backtrack: remove the current node from the path
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(root, targetSum, path, result);
        return result;
    }
};