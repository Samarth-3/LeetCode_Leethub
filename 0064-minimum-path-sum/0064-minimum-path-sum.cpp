class Solution {
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums
    int up,left=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j]; //bototm most condition
            else {
                if (i > 0)
                    up = grid[i][j]+ dp[i - 1][j]; 
                else
                    up = 1e9; // A large value if moving up is not possible (out of bounds)

                if (j > 0)
                    left =grid[i][j]+ dp[i][j - 1]; 
                else
                    left = 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
    }
};