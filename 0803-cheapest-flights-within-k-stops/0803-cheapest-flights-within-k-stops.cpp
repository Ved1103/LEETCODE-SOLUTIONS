class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].push_back({v,price});
        }
        vector<int>dis(n,1e9);
        dis[src]=0;
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});
        while(!q.empty()){
            int m = q.front().first;
            int l = q.front().second.first;
            int p = q.front().second.second;
            q.pop();
            for(auto it: adj[m]){
                if((p + it.second < dis[it.first]) && k>=l){
                    dis[it.first] = p + it.second;
                    q.push({it.first, {l+1, p+it.second}});
                }
            }
        }
        if(dis[dst]>=1e9){
            return -1;
        }
        return dis[dst];

    }
};