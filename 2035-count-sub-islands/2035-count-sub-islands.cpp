class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        int count = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid2[r][c] == 1) {
                    if (dfs(grid1, grid2, r, c, rows, cols)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int rows, int cols) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid2[r][c] == 0) {
            return true;
        }
        if (grid1[r][c] == 0) {
            return false;
        }
        grid2[r][c] = 0; // Mark the cell as visited
        bool isSubIsland = true;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (!dfs(grid1, grid2, nr, nc, rows, cols)) {
                isSubIsland = false;
            }
        }
        return isSubIsland;
    }
};