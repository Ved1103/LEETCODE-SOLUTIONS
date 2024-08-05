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
    string smallestFromLeaf(TreeNode* root) {
        string result = "~";
        dfs(root, "", result);
        return result;
    }

private:
    void dfs(TreeNode* node, string path, string& result) {
        if (!node) return;
        path = char('a' + node->val) + path;
        if (!node->left && !node->right) {
            if (path < result) {
                result = path;
            }
        }

       
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};
