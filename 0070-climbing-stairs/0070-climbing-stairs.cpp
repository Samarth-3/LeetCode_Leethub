class Solution {
public:
    int fun(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int onestep=fun(n-1,dp);
        int twostep=fun(n-2,dp);
        return dp[n]=onestep+twostep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};