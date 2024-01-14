class Solution {
    void dfs(int row,int col,int &initialcolor,vector<vector<int>>& image,int color,int delrow[],int delcol[],vector<vector<int>> &ans){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialcolor && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,initialcolor,image,color,delrow,delcol,ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,initialcolor,image,color,delrow,delcol,ans);
        return ans;
    }
};