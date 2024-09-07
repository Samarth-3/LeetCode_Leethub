class Solution {
public:
    int fun(int index,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(index < 0 || amount < 0) return 1e9; 
        if (dp[index][amount] != -1) return dp[index][amount];
        int notake=0+fun(index-1,amount,coins,dp);
        int take = 1e9;
        if(amount >= coins[index]) {
            take = 1 + fun(index, amount - coins[index], coins,dp);
        }
        
        return dp[index][amount]=min(take, notake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)) ;
        int result = fun(n - 1, amount, coins, dp);
        return (result >= 1e9) ? -1 : result;
    }
};