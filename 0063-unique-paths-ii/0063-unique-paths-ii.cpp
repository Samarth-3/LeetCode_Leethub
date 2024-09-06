class Solution {
public:
    int fun(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(m==0 && n==0){
            return obstacleGrid[m][n] == 1 ? 0 : 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up=0;
        if(obstacleGrid[m][n]==0){
            up=fun(m-1,n,obstacleGrid,dp);
        }
        int left=0;
        if(obstacleGrid[m][n]==0){
            left=fun(m,n-1,obstacleGrid,dp);
        }
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
       
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,obstacleGrid,dp);
    }
};