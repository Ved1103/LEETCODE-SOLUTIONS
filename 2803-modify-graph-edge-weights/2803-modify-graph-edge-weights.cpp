class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int s, int d, int t) {
        vector<vector<pair<int, int>>> g(n);

        for (const auto& e : edges) {
            if (e[2] != -1) {
                g[e[0]].emplace_back(e[1], e[2]);
                g[e[1]].emplace_back(e[0], e[2]);
            }
        }

        int curDist = runDijkstra(n, s, d, g);
        if (curDist < t) {
            return vector<vector<int>>();
        }

        bool matchT = (curDist == t);

        for (auto& e : edges) {
            if (e[2] != -1)
                continue;

            e[2] = matchT ? INF : 1;
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);

            if (!matchT) {
                int newDist = runDijkstra(n, s, d, g);
                if (newDist <= t) {
                    matchT = true;
                    e[2] += t - newDist;
                }
            }
        }

        return matchT ? edges : vector<vector<int>>();
    }

private:
    int runDijkstra(int n, int s, int d, const vector<vector<pair<int, int>>>& g) {
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[s] = 0;
        pq.emplace(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& [v, w] : g[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[d];
    }
};
