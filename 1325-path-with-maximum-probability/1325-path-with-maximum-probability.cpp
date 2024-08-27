class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        int size = edges.size();
        for(int i=0;i<size;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == end_node){
                return prob;
            }
            for (auto it : adj[node]) {
                int nextNode = it.first;
                double edgeProb = it.second;

                if (prob * edgeProb > maxProb[nextNode]) {
                    maxProb[nextNode] = prob * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        return 0.00;

    }
};