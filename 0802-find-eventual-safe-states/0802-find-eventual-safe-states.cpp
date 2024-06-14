class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(), 0);
        vector<vector<int>> reverseGraph(graph.size());
        for(int i = 0; i < graph.size(); ++i) {
            for(int j : graph[i]) {
                reverseGraph[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safenode;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenode.push_back(node);
            for(auto it:reverseGraph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};



//cycle detection se
// class Solution {
//     private:
//     bool dfsCheck(int node,vector<vector<int>>& graph,vector<bool> &vis,
//                   vector<bool> &pathVis,vector<bool> & check)
//     {
//         vis[node] =1;
//         pathVis[node] =1;
//         check[node] =0;
//         for(auto it:graph[node]){
//             if(!vis[it]){
//                 if(dfsCheck(it,graph,vis,pathVis,check)){
//                     check[node]=0;
//                     return true;
//                 }
//             }
//             else if(pathVis[it]){
//                 check[node]=0;
//                 return true;
//             }
//         }
//         check[node]=1;
//         pathVis[node]=0;
//         return false;
//     }
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int vertices = graph.size();
// 	    vector<bool> vis(vertices, false);
// 	    vector<bool> pathVis(vertices, false);
// 	    vector<bool> check(vertices, true);
//         vector<int>safeNodes;
//         for(int i=0;i<vertices;i++){
//             if(!vis[i]){
//                 dfsCheck(i,graph,vis,pathVis,check);
//             }
//         }
//         for(int i=0;i<vertices;i++){
//             if(check[i]==1) safeNodes.push_back(i);
//         }
//         return safeNodes;
//     }
// };