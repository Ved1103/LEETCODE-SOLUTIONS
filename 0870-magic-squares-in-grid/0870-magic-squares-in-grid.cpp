class Solution {
public:
    bool helper(vector<vector<int>>& grid, int row, int col) {
        unordered_set<int> uniqueElements;
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        // Check rows
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0;
            for (int j = 0; j < 3; ++j) {
                int val = grid[row + i][col + j];
                if (val < 1 || val > 9 || !uniqueElements.insert(val).second) return false;
                rowSum += val;
            }
            if (rowSum != sum) return false;
        }

        // Check columns
        for (int j = 0; j < 3; ++j) {
            int colSum = 0;
            for (int i = 0; i < 3; ++i) {
                colSum += grid[row + i][col + j];
            }
            if (colSum != sum) return false;
        }

        // Check diagonals
        if (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                if (helper(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
