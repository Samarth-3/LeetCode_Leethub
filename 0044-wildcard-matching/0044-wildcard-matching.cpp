class Solution {
public:
    bool fun(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && j>=0){
            for(int x=0;x<=j;x++){
                if(p[x]!='*') {
                    return false;
                }
            }
            return true;
        }
        if(j<0 && i>=0){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=fun(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=fun(s,p,i-1,j,dp) || fun(s,p,i,j-1,dp);
        }else{
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {
        int len1=s.size();
        int len2=p.size();
        if(len1==0 && len2==0){
            return true;
        }
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,-1));
        return fun(s,p,len1-1,len2-1,dp);
    }
};