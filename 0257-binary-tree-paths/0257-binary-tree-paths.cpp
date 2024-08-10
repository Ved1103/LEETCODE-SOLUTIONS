class Solution {
public:
    void solve(vector<string>& result, string s, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        string temp = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            s += temp;
            result.push_back(s);
            return;
        }
        s += temp + "->";
        solve(result, s, root->left);
        solve(result, s, root->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        solve(result, "", root);
        return result;
    }
};
