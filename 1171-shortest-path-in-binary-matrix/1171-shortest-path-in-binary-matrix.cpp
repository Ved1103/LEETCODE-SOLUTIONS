class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> v(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        v[0][0] = 1;
        vector<int> delrow = {1, -1, 0, 0, 1, 1, -1, -1};
        vector<int> delcol = {0, 0, 1, -1, 1, -1, 1, -1};
        while (!q.empty()) {
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if (x == n-1 && y == n-1) return dist;
            for (int i = 0; i < 8; i++) {
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && v[nx][ny] > dist + 1) {
                    v[nx][ny] = dist + 1;
                    q.push({dist + 1, {nx, ny}});
                }
            }
        }
        return -1;
    }
};
