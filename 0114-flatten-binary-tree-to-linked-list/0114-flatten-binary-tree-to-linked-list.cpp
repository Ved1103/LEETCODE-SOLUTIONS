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

// Iterative soln using Stack
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if (root == nullptr)
//             return;
//         if (root->left == nullptr and root->right == nullptr)
//             return;
//         stack<TreeNode*> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* temp = st.top();
//             st.pop();
//             if (temp->right != nullptr) {
//                 st.push(temp->right);
//             }
//             if (temp->left != nullptr) {
//                 st.push(temp->left);
//             }
//             if (!st.empty()) {
//                 temp->right = st.top();
//             }
//             temp->left = nullptr;
//         }
//     }
// };

// using recursion; -->O(N) and O(N)

class Solution {
public:
 TreeNode * prev = NULL ;
    void flatten(TreeNode* root) {
        
        if(root ==  NULL) return ;

        flatten(root->right);
        flatten(root->left); 

        root->right = prev; 
        root->left = NULL ; 
 
        prev = root;
    }
};
