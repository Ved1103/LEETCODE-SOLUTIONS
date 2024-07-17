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
    TreeNode* helper(unordered_set<int>& st, TreeNode* root, vector<TreeNode*>& ans) {
        if (root == nullptr) {
            return nullptr;
        }
        
        root->left = helper(st, root->left, ans);
        root->right = helper(st, root->right, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left != nullptr) {
                ans.push_back(root->left);
            }
            if (root->right != nullptr) {
                ans.push_back(root->right);
            }
            delete root;
            return nullptr;
        }
        
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;

        for(int num : to_delete){
            st.insert(num);
        }
        if (helper(st, root, ans) != nullptr) {
            ans.push_back(root);
        }
        return ans;
    }
};
