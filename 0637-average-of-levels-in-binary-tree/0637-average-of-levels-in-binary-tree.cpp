class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int t = q.size();
            double c = 0;
            for (int i = 0; i < t; i++) {
                auto p = q.front();
                q.pop();
                c += p->val;
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            res.push_back(c / t);
        }
        return res;
    }
};