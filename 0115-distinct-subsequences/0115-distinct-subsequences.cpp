class Solution {
public:
    int fun(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0 && j>=0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=fun(s,t,i-1,j-1,dp)+fun(s,t,i-1,j,dp);
        }
        return dp[i][j]=fun(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int slen=s.size();
        int tlen=t.size();
        vector<vector<int>> dp(slen,vector<int>(tlen,-1)); 
        return fun(s,t,slen-1,tlen-1,dp);
    }
};