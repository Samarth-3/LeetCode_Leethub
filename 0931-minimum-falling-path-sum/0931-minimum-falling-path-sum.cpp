class Solution {
public:
    /*
    //memoization
    int fun(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0 || j>m-1) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }
        int up=matrix[i][j]+fun(matrix,i-1,j,dp);
        int upleft=matrix[i][j]+fun(matrix,i-1,j-1,dp);
        int upright=matrix[i][j]+fun(matrix,i-1,j+1,dp);
        return dp[i][j]=min(up,min(upleft,upright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1e9));
        int ans=1e9;
        for(int x=0;x<m;x++){
            ans=min(ans,fun(matrix,n-1,x,dp));
        }
        return ans;
    }
    */
    //tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1e9));
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(i==0){
                dp[0][j] = matrix[0][j];
                continue;
            }
            int up = matrix[i][j] + dp[i-1][j];
            int upleft = (j > 0) ? matrix[i][j] + dp[i-1][j-1] : 1e9;
            int upright = (j < m - 1) ? matrix[i][j] + dp[i-1][j+1] : 1e9;
            
            dp[i][j] = min(up, min(upleft, upright));
            }
        }
        int ans=1e9;
        for(int w=0;w<m;w++){
            ans=min(ans,dp[n - 1][w]);
        }
        return ans;
    }
};