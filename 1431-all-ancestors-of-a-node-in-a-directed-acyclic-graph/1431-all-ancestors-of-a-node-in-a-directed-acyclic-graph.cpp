
class Solution {
public:
    void DFS(int node, vector<int>& visited, vector<int>& nodes, vector<vector<int>>& adj, int parent) {
        visited[node] = 1;
        if (node != parent) {
            nodes.push_back(node);
        }
        for (int i = 0; i < adj[node].size(); i++) {
            if (visited[adj[node][i]] == 0) {
                DFS(adj[node][i], visited, nodes, adj, parent);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            vector<int> visited(n, 0);
            DFS(i, visited, temp, adj, i);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }
};