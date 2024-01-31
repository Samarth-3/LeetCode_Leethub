class Solution {
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis){
    vis[row][col]=1;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    int n=vis.size();
    int m=vis[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,vis);
        }
    }
}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rowsize=grid.size();
        int colsize=grid[0].size();
        vector<vector<int>> vis(rowsize,vector<int>(colsize,0));
        int count=0;
//         for(int i=0;i<rowsize;i++){
//             if(grid[0][i]==1 && !vis[0][i]){
//                 vis[0][i]=1;
//                 dfs(0,i,grid,vis);
//             }
//             if(grid[rowsize-1][i]==1 && !vis[rowsize-1][i]){
//                 vis[rowsize-1][i]=1;
//                 dfs(rowsize-1,i,grid,vis);
//             }
//         }
        
//         for(int j=0;j<colsize;j++){
//             if(grid[j][0]==1 && !vis[j][0]){
//                 vis[j][0]=1;
//                 dfs(j,0,grid,vis);
//             }
//             if(grid[colsize-1][j]==1 && !vis[colsize-1][j]){
//                 vis[colsize-1][j]=1;
//                 dfs(colsize-1,j,grid,vis);
//             }
//         }
        
        //wrong ans with commented REASON:UNKNOWN
        
        for (int i = 0; i < rowsize; i++) {
            for (int j = 0; j < colsize; j++) {
                if ((i == 0 || i == rowsize - 1 || j == 0 || j == colsize - 1) && grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                }
            }
        }
        
        for(int i=0;i<rowsize;i++){
            for(int j=0;j<colsize;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};