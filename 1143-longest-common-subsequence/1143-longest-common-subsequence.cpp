class Solution {
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];  //step 3

        if(s[i] == t[j]) return dp[i][j] = solveMem(s,t, i-1, j-1, dp) + 1 ;
        return dp[i][j] = max(solveMem(s,t,i-1,j, dp) , solveMem(s,t,i,j-1, dp));  // step 2
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); //step 1
        return solveMem(text1, text2, n-1, m-1, dp) ;
    }
};