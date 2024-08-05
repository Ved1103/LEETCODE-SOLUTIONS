class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
            return 1; 
        }
        if (grid[row][col] == -1) {
            return 0; // Already visited
        }

        grid[row][col] = -1; // Mark this cell as visited
        int perimeter = 0;
        perimeter += dfs(grid, row - 1, col, n, m); 
        perimeter += dfs(grid, row + 1, col, n, m);  
        perimeter += dfs(grid, row, col - 1, n, m); 
        perimeter += dfs(grid, row, col + 1, n, m); 
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, n, m);
                }
            }
        }
        return 0;
    }
};
