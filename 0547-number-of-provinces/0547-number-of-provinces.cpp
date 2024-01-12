class Solution {
    void bfs(int node, vector<int> adjlist[], vector<int>& vis) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            for (auto it : adjlist[currNode]) {
                if (vis[it] == 0) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sizee = isConnected.size();
        vector<int> adjlist[sizee];

        // Convert matrix to adjacency list
        for (int i = 0; i < sizee; i++) {
            for (int j = 0; j < sizee; j++) {
                if (isConnected[i][j] == 1) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        vector<int> vis(sizee, 0); // Use vector instead of an array
        int count = 0;

        for (int i = 0; i < sizee; i++) {
            if (vis[i] == 0) {
                count++;
                bfs(i, adjlist, vis);
            }
        }

        return count;
    }
};
