class Solution {
    void bfs(vector<vector<int>> &vis, int row, int col, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1}; // Changes for 4 directions

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse the four cardinal directions
            for (int k = 0; k < 4; ++k) {
                int nrow = row + dir[k];
                int ncol = col + dir[k + 1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (vis[row][col] == 0 && grid[row][col] == '1') {
                    count++;
                    bfs(vis, row, col, grid);
                }
            }
        }

        return count;
    }
};
