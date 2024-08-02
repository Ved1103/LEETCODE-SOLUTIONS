class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end());
        int temp = points[0][1];
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] > temp) {
                ans++;
                temp = points[i][1];
            } else {
                temp = min(temp, points[i][1]);
            }
        }
        return ans;
    }
};