class Solution {
public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         queue<int>q;
//         vector<int>color(graph.size(),-1);
//         for(int i=0;i<graph.size();i++){
//             if(color[i] == -1){
                
//                 q.push(i);
//                 color[i]=0;
//                 while(!q.empty()){
//                     int node = q.front();
//                     q.pop();
//                     for(auto it: graph[node]){
//                         // if the adjacent color is yet not colored
//                         if(color[it] == -1){
//                             color[it] = !color[node];
//                             q.push(it);
//                         }
//                         else{
//                             if(color[it]==color[node])return false;
//                         }
//                     }
//                 }
//             }
//         }return true;
//     }


//dfs sol

bool dfs(int start,int col, vector<vector<int>>&graph, vector<int>&color){
        color[start] = col;
        for(auto &it: graph[start]){
            if(color[it]==-1){
                if(dfs(it,!col,graph,color)==false){
                    return false;
                };
            }
            else{
                if(color[it] == col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};