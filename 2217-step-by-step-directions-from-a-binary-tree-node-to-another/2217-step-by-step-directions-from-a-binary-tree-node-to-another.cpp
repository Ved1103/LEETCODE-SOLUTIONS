/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    string ans;
    int cnt;

    TreeNode* lca(TreeNode* node, int s, int d) {
        if (node == NULL || node->val == s || node->val == d)
            return node;

        TreeNode* left = lca(node->left, s, d);
        TreeNode* right = lca(node->right, s, d);

        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        }
        return node;
    }
    void findPath(TreeNode* node, int s, int d, string& str) {
        if (node == NULL)
            return;
        if (node->val == s) {
            cnt = str.size();
        }
        if (node->val == d) {
            ans = str;
        }

        str += "L";
        findPath(node->left, s, d, str);
        str.pop_back();
        str += "R";
        findPath(node->right, s, d, str);
        str.pop_back();

        return;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* LCA = lca(root, startValue, destValue);
        string a = "";
        findPath(LCA, startValue, destValue, a);

        string str = "";
        for (int i = 0; i < cnt; i++) {
            str += "U";
        }
        return (str + ans);
    }
};