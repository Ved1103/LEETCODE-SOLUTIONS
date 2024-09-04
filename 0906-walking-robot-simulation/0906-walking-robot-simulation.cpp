class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, dir = 0;
        int ans = 0;

        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1)
                dir = (dir + 1) % 4; // turn right
            else if (commands[i] == -2)
                dir = (dir + 3) % 4; // turn left
            else {
                for (int j = 0; j < commands[i]; j++) {
                    int dx = x, dy = y;
                    if (dir == 0)
                        dy++; // up
                    else if (dir == 1)
                        dx++; // right
                    else if (dir == 2)
                        dy--; // down
                    else if (dir == 3)
                        dx--; // left

                    // Check if the new position is blocked
                    if (obstacleSet.count({dx, dy}) > 0) {
                        break; // obstacle found, stop moving
                    }

                    x = dx;
                    y = dy;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};