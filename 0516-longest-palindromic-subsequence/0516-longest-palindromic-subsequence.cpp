class Solution {
public:
    int solve(string &s, string &r, int i1, int i2, vector<vector<int>> &dp){
        if(i1<0 || i2<0){
            return 0;
        }

        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }

        if(s[i1]==r[i2]){
            return dp[i1][i2] =  1+solve(s, r, i1-1, i2-1, dp);
        }

    return dp[i1][i2] = max(solve(s,r,i1-1, i2, dp), solve(s,r,i1,i2-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return solve(s, r, s.size()-1, s.size()-1, dp);
    }
};