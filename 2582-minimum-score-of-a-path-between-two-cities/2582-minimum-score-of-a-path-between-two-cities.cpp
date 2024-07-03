class Solution {
public:
    void solve(int s, int& ans, vector<vector<vector<int>>>& g, vector<bool>& v) {
        if (v[s]) return;
        v[s] = true;
        for (auto& i : g[s]) {
            ans = min(ans, i[1]);
            solve(i[0], ans, g, v);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> g(n + 1);
        for (auto i : roads) {
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        int ans = INT_MAX;
        vector<bool> v(n + 1, false);
        solve(1, ans, g, v);
        return ans == INT_MAX ? -1 : ans;
    }
};