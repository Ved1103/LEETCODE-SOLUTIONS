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
public:
    int helper(TreeNode* root, int curr) {
        if (root == nullptr) {
            return 0;
        }
        curr = curr * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return curr;
        }
        int leftSum = helper(root->left, curr);
        int rightSum = helper(root->right, curr);
        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};
