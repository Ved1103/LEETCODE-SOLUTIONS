
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> visited;
        visited.insert("0,0");

        for (char ch : path) {
            if (ch == 'N') {
                y++;
            } else if (ch == 'S') {
                y--;
            } else if (ch == 'E') {
                x++;
            } else if (ch == 'W') {
                x--;
            }

            string position = to_string(x) + "," + to_string(y);
            if (visited.count(position)) {
                return true;
            }
            visited.insert(position);
        }

        return false;
    }
};