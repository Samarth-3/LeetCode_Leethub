class Solution {
public:
    int fun(string &word1, string &word2,int i,int j,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=fun(word1,word2,i-1,j-1,dp);
        }
        else{
            return dp[i][j]=1+min(fun(word1,word2,i,j-1,dp),min(fun(word1,word2,i-1,j,dp),fun(word1,word2,i-1,j-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return fun(word1,word2,len1-1,len2-1,dp);
    }
};