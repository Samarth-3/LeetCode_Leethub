class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector < int > adj[numCourses];
        int indegree[numCourses];
        
        // Initialize indegree array to 0
        for (int i = 0; i < numCourses; ++i) {
            indegree[i] = 0;
        }
       
        
        //here below adj list bana di
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            // indegree[prerequisites[i][0]] ++;
        }
        
        //indegree ka array in making
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
             ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    
                }
            }
        }
        if(ans.size()==numCourses){
        return true;
        }
        return false;
    }
};