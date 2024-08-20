class Solution {
public:
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
};