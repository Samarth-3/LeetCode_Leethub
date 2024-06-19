class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int t=roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long >dis(n,1e15),ways(n,0);
        ways[0]=1;
        dis[0]=0;
        int mod=(int)1e9+7;
        while(!pq.empty()){
            int node=pq.top().second;
            long long dist=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                long long adjW=it.second;
                if(dist+adjW < dis[adjNode]){
                    dis[adjNode]=dist+adjW;
                    pq.push({dist+adjW,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dist + adjW ==dis[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};