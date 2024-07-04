class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& adj, int node, vector<int>& ans, unordered_set<int>& visited) {
        visited.insert(node);
        ans.push_back(node);
        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(adj, neighbor, ans, visited);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> adj;
        for (auto it : adjacentPairs) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int start = 0;
        for (auto it : adj) {
            if (it.second.size() == 1) {
                start = it.first;
                break;
            }
        }
        unordered_set<int> visited;
        dfs(adj, start, ans, visited);
        return ans;
    }
};