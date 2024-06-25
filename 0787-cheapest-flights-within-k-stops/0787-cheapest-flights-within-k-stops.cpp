#include <queue>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for (const auto& flight : flights) {  // Correctly iterate over the flights vector
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];
            adj[u].push_back({v, p});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0,{src,0}}); //{stops,{node,cost}}
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
             // if (stops > k) continue;
            for(auto it:adj[node]){
                int nn=it.first;
                int dd=it.second;
                if(dist[nn]>cost+dd && stops<=k){
                    dist[nn]=cost+dd;
                    q.push({stops+1,{nn,cost+dd}});
                }
            }
        }
        
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};