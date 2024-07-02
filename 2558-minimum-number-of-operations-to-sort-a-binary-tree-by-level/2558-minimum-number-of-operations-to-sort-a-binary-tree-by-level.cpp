class Solution {
public:
    int helper(vector<int>& vec) {
        vector<pair<int, int>> res;
        int swaps = 0;
        for (int i = 0; i < vec.size(); i++) {
            res.push_back({vec[i], i});
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            while (res[i].second != i) {
                swaps++;
                swap(res[i], res[res[i].second]);
            }
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> vec;
            for (int i = 0; i < level_size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                vec.push_back(temp->val);
            }
            ans += helper(vec);
        }
        return ans;
    }
};