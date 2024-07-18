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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if (root == NULL)
            return ans;
        q.push(root);
        int currMax = INT_MIN;
        while (q.size()) {
            int currsize = q.size();
            while (currsize--) {
                TreeNode* node = q.front();
                q.pop();
                currMax = max(currMax, node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            ans.push_back(currMax);
            currMax = INT_MIN;
        }
        return ans;
    }
};