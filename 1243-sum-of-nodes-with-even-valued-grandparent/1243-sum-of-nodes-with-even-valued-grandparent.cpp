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
    void helper(int &ans, TreeNode* root){
        if (root == nullptr) {
            return;
        }
        if (root->val % 2 == 0) {
            if (root->left != nullptr) {
                if (root->left->left != nullptr) {
                    ans += root->left->left->val;
                }
                if (root->left->right != nullptr) {
                    ans += root->left->right->val;
                }
            }
            if (root->right != nullptr) {
                if (root->right->left != nullptr) {
                    ans += root->right->left->val;
                }
                if (root->right->right != nullptr) {
                    ans += root->right->right->val;
                }
            }
        }
        helper(ans, root->left);
        helper(ans, root->right);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        helper(ans, root);
        return ans;
    }
};
