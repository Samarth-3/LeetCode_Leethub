class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        vector<vector<int>> dist(n, vector<int>(m, 10000));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); 
        dist[0][0] = 1;
        
        int r[]={-1,-1,-1,0,1,1,1,0};
        int c[]={-1,0,1,1,1,0,-1,-1};
        
        while(!pq.empty()){
            int rr=pq.top().second.first;
            int cc=pq.top().second.second;
            int d=pq.top().first;
            if (rr == n - 1 && cc == m - 1) return d+1;
            pq.pop();
            for(int i=0;i<8;i++){
                int nrow=r[i]+rr;
                int ncol=c[i]+cc;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && d + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol]=d+1;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};