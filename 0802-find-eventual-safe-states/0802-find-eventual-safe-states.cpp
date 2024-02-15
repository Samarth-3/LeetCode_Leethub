class Solution {
    private:
    bool dfsCheck(int node,vector<vector<int>>& graph,vector<bool> &vis,
                  vector<bool> &pathVis,vector<bool> & check)
    {
        vis[node] =1;
        pathVis[node] =1;
        check[node] =0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfsCheck(it,graph,vis,pathVis,check)){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int vertices = graph.size();
	    vector<bool> vis(vertices, false);
	    vector<bool> pathVis(vertices, false);
	    vector<bool> check(vertices, true);
        vector<int>safeNodes;
        for(int i=0;i<vertices;i++){
            if(!vis[i]){
                dfsCheck(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<vertices;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};