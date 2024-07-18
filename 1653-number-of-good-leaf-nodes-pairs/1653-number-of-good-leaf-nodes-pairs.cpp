class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node)
            return {};

        if (!node->left && !node->right) {
            return {0};
        }

        auto leftDepths = dfs(node->left, distance, count);
        auto rightDepths = dfs(node->right, distance, count);

        for (int dl : leftDepths) {
            for (int dr : rightDepths) {
                if (dl + dr + 2 <= distance) {
                    count++;
                }
            }
        }

    
        vector<int> depths;
        for (int d : leftDepths) {
            depths.push_back(d + 1);
        }
        for (int d : rightDepths) {
            depths.push_back(d + 1);
        }

        return depths;
    }
};