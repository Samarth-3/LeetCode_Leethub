class Solution {
public:
    int fun(int index,int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(amount<0 || index<0){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int notake=fun(index-1,amount,coins,dp);
        int take=fun(index,amount-coins[index],coins,dp);
        
        return dp[index][amount]=take+notake;
    }
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return fun(coins.size()-1,amount,coins,dp);
 
    }
};