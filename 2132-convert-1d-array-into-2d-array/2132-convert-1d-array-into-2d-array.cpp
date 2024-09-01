class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int totalsize = m * n;
        int sz = original.size();
        if (sz != totalsize) {
            return {};
        }
        int temp = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[temp];
                temp++;
            }
        }
        return ans;
    }
};