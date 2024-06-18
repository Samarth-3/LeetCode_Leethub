class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1000000));
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); 
        diff[0][0] = 0;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        
        while(!pq.empty()){
            int rr=pq.top().second.first;
            int cc=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            if(rr==n-1 && cc==m-1) return d;
            for(int i=0;i<4;i++){
                int nrow=r[i]+rr;
                int ncol=c[i]+cc;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  ){
                    int nextEffort = max(d, abs(heights[nrow][ncol] - heights[rr][cc]));
                    if(nextEffort<diff[nrow][ncol]){
                        diff[nrow][ncol]=nextEffort;
                        pq.push({nextEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};